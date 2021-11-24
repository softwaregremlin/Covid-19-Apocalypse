#include "processFrameGameOver.c"
#include "processFrameIntro.c"
#include "processFramePreIntro.c"

unsigned int testColour = 0;

void ProcessFrame() {

	if (gGame.State == GameStatePreIntro) {

		InputPoll();
		GamePreIntroFrame();
		return;
	}


	if (gGame.State == GameStateIntro) {

		InputPoll();
		GameIntroFrame();
		return;
	}


	if (gGame.State == GameStateOver) {
		
		GameInitialise();
		BeastsInitialise();
		gGun.State = GunStateLoaded;
		GameOverDisplayFrame();

		//InputPoll();
		//GameIntroFrame();
		return;
	}

	InputPoll();

	GraphicsStartDrawing();
	// 

	// Background
	BackgroundDraw();

	// BEAST
	BeastsMoveAndDraw();

	// Gun
	GunDraw();

	// Score / Health
	GameCheckHealthBonus();
	ScreenTextDraw();

	// Fire Gun
	GunProcessFire();

	// Crosshairs!
	float scaledWidth = gGraphicsImages[1].Width * gGraphicsImages[1].ScaleX,
		  scaledHeight = gGraphicsImages[1].Height * gGraphicsImages[1].ScaleY;

	GraphicsBlitImageRegion(g_GraphicsImage1,
		gInputPointerX - (scaledWidth / 2),
		gInputPointerY - (scaledHeight / 2),
		gGraphicsImages[1].RegionX, gGraphicsImages[1].RegionY,
		gGraphicsImages[1].Width, gGraphicsImages[1].Height,
		gGraphicsImages[1].ScaleX, gGraphicsImages[1].ScaleY);

	GraphicsStopDrawing();

	if (InputEscapePressed()) gFinished = 1;

	//Toggle Full Screen / Window!
	InputAltEnterPressed();

}