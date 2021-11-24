int GameOverWidth = 12,
GameOverHeight = 13,
GameOverLength = 156,
GameOverXOffset = 13,
GameOverYOffset = 4,
GameOverFrame = 0,
GameOverFrameCount = 0,
GameOverFrameOffset = 0;

   

int gGameOverTiles[] = { 
	197, 201, 199, 0, 197, 199, 197, 199, 197, 199, 203, 240, 
	242, 0, 222, 197, 252, 242, 242, 244, 242, 242, 242, 0, 
	242, 246, 248, 203, 201, 248, 242, 250, 252, 242, 203, 240,
	242, 197, 252, 242, 0, 242, 242, 0, 0, 242, 242, 0,
	250, 252, 0, 222, 0, 222, 222, 0, 0, 222, 205, 240, 
	
	197, 201, 199, 254, 0, 254, 203, 240, 203, 201, 199, 0, 
	242, 0, 242, 242, 0, 242, 242, 0, 242, 0, 242, 0, 
	242, 0, 242, 242, 0, 242, 203, 240, 203, 201, 252, 0, 
	242, 0, 242, 250, 199, 242, 242, 0, 242, 250, 199, 0, 
	250, 201, 252, 0, 250, 252, 205, 240, 222, 0, 222, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 67, 79, 86, 73, 68, 0, 49, 57, 0, 0, 0, 
	0, 0, 72, 65, 83, 0, 87, 79, 78, 0, 0, 0 };

void GameOverDisplayFrame() {
	GraphicsStartDrawing();
	// GraphicsSetBGColour(0, 0, 0);
	BackgroundDraw();

	GameOverFrameCount++;
	if (GameOverFrameCount > 10) GameOverFrameOffset = 1;
	if (GameOverFrameCount > 20) { GameOverFrameCount = 0; GameOverFrameOffset = 0; }

	int tt_x = 0, tt_y = 0;
	for (int tt = 0; tt < GameOverLength; tt++) {

		int tileAdd = 0;
		if (tt_y < 10) tileAdd = gGameOverTiles[tt] == 0 ? 0 : GameOverFrameOffset;

		TileDrawCharPos(gGameOverTiles[tt] + tileAdd, tt_x + GameOverXOffset, tt_y + GameOverYOffset);
		tt_x++;
		if (tt_x == GameOverWidth) {
			tt_x = 0;
			tt_y++;
		}
	}

	GameOverFrame++;
	if (GameOverFrame == 450) {
		gGame.State = GameStateIntro;
		GameOverFrame = 0;
	}

	GraphicsStopDrawing();

	if (InputEscapePressed()) gFinished = 1;
}
