int GameIntroWidth = 34,
GameIntroHeight = 16,
GameIntroTiles = 34 * 16,
GameIntroXOffset = 5,
GameIntroYOffset = 4,
GameIntroTextInSights = 0,
GameIntroFrameCount = 0,
GameIntroFrameOffset = 0;



int gGameIntroTiles[] =
{
0, 197, 201, 248, 0, 0, 197, 201, 199, 0, 0, 203, 248, 0, 0, 203, 248, 0, 203, 248, 0, 203, 201, 199, 0, 0, 0, 254, 197, 201, 199, 0, 0, 0,
197, 244, 201, 240, 0, 197, 244, 201, 244, 199, 0, 242, 242, 0, 0, 242, 242, 0, 242, 242, 0, 242, 201, 201, 199, 0, 0, 242, 242, 0, 242, 0, 0, 0,
242, 242, 0, 0, 0, 205, 248, 0, 205, 248, 0, 242, 242, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 242, 199, 0, 242, 250, 201, 242, 0, 0, 0,
242, 242, 0, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 222, 246, 201, 252, 0, 0, 0,
242, 242, 0, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 0, 0, 0, 0, 0, 0, 0,
242, 242, 0, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 242, 242, 0, 0, 0, 0, 0, 0, 0, 0,
203, 248, 0, 0, 0, 203, 248, 0, 203, 248, 0, 250, 244, 199, 197, 244, 252, 0, 242, 242, 0, 242, 242, 0, 242, 252, 0, 0, 0, 0, 0, 0, 0, 0,
250, 244, 201, 248, 0, 250, 244, 201, 244, /**/ 252, /**/ 0, 0, 250, 244, 244, 252, 0, 0, 242, 242, 0, 242, 242, 201, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 250, 201, 240, 0, 0, 250, 201, 252, 0, 0, 0, 0, 250, 252, 0, 0, 0, 246, 240, 0, 246, 201, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 197, 199, 203, 199, 197, 199, 197, 240, 0, 197, 199, 254, 254, 0, 254, 203, 199, 197, 240, 203, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
197, 252, 242, 242, 240, 242, 242, 242, 0, 197, 252, 242, 242, 250, 199, 242, 242, 240, 242, 0, 242, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
246, 201, 240, 242, 252, 242, 242, 242, 0, 246, 201, 240, 242, 0, 250, 242, 242, 252, 250, 199, 203, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
242, 0, 242, 242, 0, 242, 242, 242, 0, 242, 0, 242, 242, 0, 197, 252, 242, 0, 0, 242, 242, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
222, 0, 222, 222, 0, 250, 252, 250, 240, 222, 0, 222, 246, 240, 222, 0, 222, 0, 246, 252, 246, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int gGameIntroStartText[] = {
							83, 84, 65, 82, 84, 0, 0,
							71, 65, 77, 69, 0, 0, 0 };

int gGameLoadingText[] = { 268, 271, 257, 260, 265, 270, 263 };


int GameIntroStartTextInSights() {

	//if (gGame.Ammo == 0) return 0;

	float tileScaleX = (float)gGraphicsSettings.WindowWidth / (float)(TILES_X_COUNT * TILE_SIZE),
		tileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(TILES_Y_COUNT * TILE_SIZE);
	//int tileZ = gBeasts1[index].zPos;
	int tileX = 30, tileY = 15, tileXCount = 5, tileYCount = 2;

	// tileX -= tileXCenterOffset;


	float xPixel = (float)tileX * TILE_SIZE * tileScaleX,
		yPixel = (float)tileY * TILE_SIZE * tileScaleY,
		widthPixel = TILE_SIZE * tileScaleX * tileXCount,
		heightPixel = TILE_SIZE * tileScaleY * tileYCount;

	return InRectangle(gInputPointerX, gInputPointerY, xPixel, yPixel, widthPixel, heightPixel);

}

int GameIntroStartTextGetTile(int tileIndex) {
	if (!GameIntroStartTextInSights()) return tileIndex;
	return tileIndex == 0 ? 0 : tileIndex + (12 * 16);
}


void IntroDrawTitle() {
	int tt, tt_x = 0, tt_y = 0;
	for (tt = 0; tt < GameIntroTiles; tt++) {
		TileDrawCharPos(gGameIntroTiles[tt] + (gGameIntroTiles[tt] == 0 ? 0 : GameIntroFrameOffset), tt_x + GameIntroXOffset, tt_y + GameIntroYOffset);
		tt_x++;
		if (tt_x == GameIntroWidth) {
			tt_x = 0;
			tt_y++;
		}
	}
}

void IntroLoadingScreen() {
	if (gBypassLoading) return;

	GraphicsStartDrawing();
	IntroDrawTitle();

	int tt_x = 14, tt_y = 20;
	for (int tt = 0; tt < 7; tt++) {
		TileDrawCharPos(GameIntroStartTextGetTile(gGameLoadingText[tt]), tt_x, tt_y);
		tt_x++;
	}
	GraphicsStopDrawing();
}


void GameIntroFrame() {

	GraphicsStartDrawing();
	// GraphicsSetBGColour(0, 0, 0);
	BackgroundDraw();

	// Intro title
	GameIntroFrameCount++;
	if(GameIntroFrameCount > 10) GameIntroFrameOffset = 1;
	if (GameIntroFrameCount > 20) { GameIntroFrameCount = 0; GameIntroFrameOffset = 0; }

	IntroDrawTitle();

	// Button!	
	int tt, tt_x = 0, tt_y = 0;

	int startGameXOffset = 30, startGameYOffset = 15;
	tt_x = startGameXOffset; tt_y = startGameYOffset;
	for (tt = 0; tt < 14; tt++) {  
		TileDrawCharPos(GameIntroStartTextGetTile(gGameIntroStartText[tt]), tt_x, tt_y);
		tt_x++;
		if (tt == 6) {
			tt_x = startGameXOffset,
			tt_y++;
		}
	}
	
	// Start Button Shot
	if (gInputFire && GameIntroStartTextInSights()) {
		SoundPlayShot();
		gGame.State = GameStateGame;
		// TempSecondIntro = 1;
	}


	// Crosshairs!
	float scaledWidth = gGraphicsImages[1].Width * gGraphicsImages[1].ScaleX,
		scaledHeight = gGraphicsImages[1].Height * gGraphicsImages[1].ScaleY;

	GraphicsBlitImageRegion(g_GraphicsImage1,
		gInputPointerX - (scaledWidth / 2),
		gInputPointerY - (scaledHeight / 2),
		gGraphicsImages[1].RegionX, gGraphicsImages[1].RegionY,
		gGraphicsImages[1].Width, gGraphicsImages[1].Height,
		gGraphicsImages[1].ScaleX, gGraphicsImages[1].ScaleY);


	if (InputEscapePressed()) gFinished = 1;


	GraphicsStopDrawing();

	InputAltEnterPressed();

}
