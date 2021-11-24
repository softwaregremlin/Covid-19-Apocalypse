enum { GunStateLoaded, GunStateEmpty, GunStateReloading };

typedef struct {
	int State,
		ReloadFlashFrame,
		ReloadFlashFrames,
		ReloadingFrame,
		ReloadingFramesPerBullet,
		ReloadingFrames,
		GunFlashFrame,
		GunFlashFrames,
		GunFlashTiles[3];
} GunStruct;

GunStruct gGun = { 
		.State = GunStateLoaded, 
		.ReloadFlashFrames = 20, .ReloadingFramesPerBullet = 5,
		.GunFlashFrames = 10,
		.GunFlashTiles = { 119, 120, 121}
		};

/////////////////////////////////////////

void GunDraw() {
	//int gunTileX = gInputPointerX / 17;
	int gunTileX = (int)
		(((float)gInputPointerX / (float) gGraphicsSettings.WindowWidth) * (float)TILES_X_COUNT) - 2;
	if (gunTileX > 35) gunTileX = 35;
	if (gunTileX < 0)  gunTileX = 0;

	if (gGun.GunFlashFrame > 0) {
		TileDrawArrayRowSection(gGun.GunFlashTiles, 22, 3, gunTileX + 1);
		gGun.GunFlashFrame--;
	}

	TileDrawArrayRowSection(TilesGun[0], 23, 4, gunTileX);
	TileDrawArrayRowSection(TilesGun[1], 24, 5, gunTileX);
}

void GunProcessFire() {
	if (gInputFire) {
		if (gGun.State == GunStateLoaded) {
			gGame.Ammo--;
			SoundPlayShot();
			gGun.GunFlashFrame = gGun.GunFlashFrames;
			if (gGame.Ammo == 0) gGun.State = GunStateEmpty;
		}
		else { SoundPlayEmpty(); }
	}

	//if(gInputPointerY >= (int)((float)gGraphicsSettings.WindowHeight * 0.95) 
	if(InputReloadButton()
		&& gGame.Ammo < 6 && gGun.State != GunStateReloading) {
		SoundPlayReload();
		gGun.State = GunStateReloading;
	}
}

int GunFlashTextShowing() { return gGun.ReloadFlashFrame < gGun.ReloadFlashFrames; }

void GunFlashTextAdvance() {
	gGun.ReloadFlashFrame++;
	if (gGun.ReloadFlashFrame == gGun.ReloadFlashFrames * 2)  gGun.ReloadFlashFrame = 0;
}

void GunReloadingAdvance() {
	gGun.ReloadingFrame++;
	if (gGun.ReloadingFrame % gGun.ReloadingFramesPerBullet == 0) {
		gGame.Ammo++;
		if (gGame.Ammo == 6) {
			gGun.State = GunStateLoaded;
		}
	}
}