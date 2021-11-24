#define INPUT_POINTER_SPEED 15

int gInputFireHeld = 0, gTriangleHeld = 0;

void InputInitialise() {
	memset(&g_VitaPad, 0, sizeof(g_VitaPad));
	sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);
	
	gInputPointerX = GRAPHICS_WINDOW_WIDTH / 2;
	gInputPointerY = GRAPHICS_WINDOW_HEIGHT / 2;
}

unsigned int InputStartPressed() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return g_VitaPad.buttons & SCE_CTRL_START;
}

unsigned int InputCrossPressed() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return g_VitaPad.buttons & SCE_CTRL_CROSS;
}

unsigned int InputTrianglePressed() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return g_VitaPad.buttons & SCE_CTRL_TRIANGLE;
}

unsigned int InputCirclePressed() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return g_VitaPad.buttons & SCE_CTRL_CIRCLE;
}


unsigned int InputLeft() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return (g_VitaPad.lx < MIN_ANALOG_STICK_THRESHOLD) || (g_VitaPad.buttons & SCE_CTRL_LEFT);
}

unsigned int InputRight() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return (g_VitaPad.lx > MAX_ANALOG_STICK_THRESHOLD) || (g_VitaPad.buttons & SCE_CTRL_RIGHT);
}

unsigned int InputUp() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return (g_VitaPad.ly < MIN_ANALOG_STICK_THRESHOLD) || (g_VitaPad.buttons & SCE_CTRL_UP);
}

unsigned int InputDown() {
	sceCtrlPeekBufferPositive(0, &g_VitaPad, 1);
	return (g_VitaPad.ly > MAX_ANALOG_STICK_THRESHOLD) || (g_VitaPad.buttons & SCE_CTRL_DOWN);
}

int InputEscapePressed() {	return 0; }
int InputAltEnterPressed() { return 0; }

int InputReloadButton() {
	return InputCirclePressed();
}


void InputPoll() {

	// Move the cursor with left stick or arrows
	if(InputLeft()) gInputPointerX -= INPUT_POINTER_SPEED;
	if(InputRight()) gInputPointerX += INPUT_POINTER_SPEED;
	if(InputUp()) gInputPointerY -= INPUT_POINTER_SPEED;
	if(InputDown()) gInputPointerY += INPUT_POINTER_SPEED;	
	
	// Confine to the screen
	if(gInputPointerX < 0) gInputPointerX = 0;
	if(gInputPointerY < 0) gInputPointerY = 0;
	if(gInputPointerX > GRAPHICS_WINDOW_WIDTH) gInputPointerX = GRAPHICS_WINDOW_WIDTH;
	if(gInputPointerY > GRAPHICS_WINDOW_HEIGHT) gInputPointerY = GRAPHICS_WINDOW_HEIGHT;
	
	// Fire (X button)
	gInputFire = 0;
	if (!(InputCrossPressed())) gInputFireHeld = 0;
	if (!gInputFireHeld && InputCrossPressed()) {
		gInputFireHeld = 1;
		gInputFire = 1;
	}	
	
	// Triangle - Mute
	if (!(InputTrianglePressed())) gTriangleHeld = 0;
	if (!gTriangleHeld && InputTrianglePressed()) {
		if(g_soundBackgroundMusicIsPlaying) {
			soundStopBackgroundMusic();
		} else {
			soundStartBackgroundMusicLoop();
		}	
		gTriangleHeld = 1;
	}	
	
}