void Exit() {

	SoundDenitialise();	
	
	////////////////////////////////////////////
	// FTP!!
	// launchFtpServer();
	/////////////////////
	
	/*
	 * vita2d_fini() waits until the GPU has finished rendering,
	 * then we can free the assets freely.
	 */
	vita2d_fini();
	vita2d_free_font(g_VitaFont);	
	
	for (int ee = 1; ee <= g_Game.LevelCount; ee++) {
		vita2d_free_texture(g_Images.Enemy[ee-1]);
	}

	for (int bb = 1; bb <= g_Game.LevelCount / 2; bb++) {
		vita2d_free_texture(g_Images.Background[bb-1]);
	}

	vita2d_free_texture(g_Images.Rock);	
	vita2d_free_texture(g_Images.Band);	
	vita2d_free_texture(g_Images.Player);	
	
	sceKernelExitProcess(0);
}
