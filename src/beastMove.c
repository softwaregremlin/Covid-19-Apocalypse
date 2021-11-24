

void BeastDetectHit(int index) {

	// SHOT! 
	if (!(gInputFire && gBeasts1[index].State == BeastStateWalking && gBeasts1[index].zPos >= 2)) return;

	if (!BeastBulletCollisions(index)) return;

	gBeasts1[index].Hits++;

	// Non-fatal shots -  move state to shot
	if (gBeasts1[index].Hits < gBeast1SettingsWalking.HitCount) {
			gBeasts1[index].State = BeastStateShot;
			gBeasts1[index].FrameShot = 0;
			return;
	}

	// Final hit - move state to dead
	SoundPlayKill();
	gGame.Score += 20;

	gBeasts1[index].State = BeastStateDead;
	gBeasts1[index].FrameDead = 0;
	gBeasts1[index].AnimationFrame = 0;

}

void BeastMoveShot(int index) {

	// Advance Frame
	gBeasts1[index].FrameShot++;

	// Drive back after 1/4 sec
	if (gBeasts1[index].FrameShot == 12) gBeasts1[index].zPos--;

	// Recover back to walking
	if (gBeasts1[index].FrameShot < 24) return;
	gBeasts1[index].State = BeastStateWalking;
	gBeasts1[index].FrameShot = 0;
}

void BeastAnimateAlive(int index) {

	// Initial Delay
	if (gBeasts1[index].InitialDelay > 0) {
		gBeasts1[index].InitialDelay--;
		return;
	}

	// Toggle animation every 6 Frames (1/10th sec)
	gBeasts1[index].Frame++;
	
	if (gBeasts1[index].Frame % 6 != 0) return;


	gBeasts1[index].AnimationFrame = !gBeasts1[index].AnimationFrame;
}

void BeastAnimateDead(int index) {
	gBeasts1[index].FrameDead++;
	if (gBeasts1[index].FrameDead > 10) gBeasts1[index].AnimationFrame = 1;
	
	// Scroll off the screen
	if (!(gBeasts1[index].FrameDead >= BackgroundScrollSpeed && BackgroundIsScrolling)) return;

	gBeasts1[index].xPos--;
	gBeasts1[index].FrameDead = 0;

	// Respawn once off-screen
	if (gBeasts1[index].xPos < -8) BeastInitialise(index);	
}

int gGameBiteSound = 0;

void BeastMoveWalking(int index) {

	if (gBeasts1[index].Frame != 24) return;

	gBeasts1[index].Frame = 0;

	if (gBeasts1[index].State != BeastStateWalking &&
		gBeasts1[index].State != BeastStateBiting) return;

	gBeasts1[index].zPos += gBeasts1[index].Direction == DirectionForward ? 1 : -1;

	// Bite
	if (gBeasts1[index].zPos == 5) {
		gBeasts1[index].State = BeastStateBiting;

		if (gGameBiteSound == 0) {
			SoundPlayBite1();
		}
		else{
			SoundPlayBite2();
		}
		gGameBiteSound = !gGameBiteSound;

		//gGame.Health -= gGame.Health > 0 ? 5 : 0;
		gGame.Health -= gGame.Health > 0 ? 10 : 0;
		if (gGame.Health <= 0) {
			gGame.State = GameStateOver;
		}
		
		gBeasts1[index].yPos = randMinMax(4,9);
		return;
	}



	// Bounce
	if (gBeasts1[index].zPos >= 0 && gBeasts1[index].zPos <= 5) return;
	gBeasts1[index].zPos = gBeasts1[index].zPos > 5 ? 4 : 0;

	if (gBeasts1[index].State == BeastStateBiting) gBeasts1[index].State = BeastStateWalking;

	gBeasts1[index].Direction = 
		gBeasts1[index].Direction == DirectionForward ? DirectionBackward : DirectionForward;
	
}

void BeastMove(int index) {

	BeastDetectHit(index);
	if (gBeasts1[index].State == BeastStateShot) BeastMoveShot(index);
	if (gBeasts1[index].State != BeastStateDead) BeastAnimateAlive(index);
	if (gBeasts1[index].State == BeastStateDead) BeastAnimateDead(index);
	BeastMoveWalking(index);
}

void BeastsMoveAndDraw() {
	// Move
	for (int bb = 0; bb < BEASTS_MAX; bb++) BeastMove(bb);

	// Draw
	// Stack from back to front
	for (int zz = 0; zz <= 5; zz++) {

		// Then by index if we are in the same layer
		for (int bb = 0; bb < BEASTS_MAX; bb++) {
			if (gBeasts1[bb].zPos == zz) {
				BeastDraw(bb);
				BeastDrawCollisionRectangle(bb,0);
				BeastDrawCollisionRectangle(bb,1);
			}
		}
	}

	// GraphicsDrawCollisionRectangle(100, 100, 100, 100);
}