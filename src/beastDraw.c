

// TODO put into an Array
int BeastGetYpos(int index, int zPos) {
	if (zPos == 0) return 12;
	if (zPos == 1) return 12;
	if (zPos == 2) return 11;
	if (zPos == 3) return 8;
	if (zPos == 4) return 9;
	if (zPos == 5) return gBeasts1[index].yPos;
	return 0;
}

int BeastGetTile(int index, int sourceTile) {


	if (gBeasts1[index].State != BeastStateShot) return sourceTile;

	// Translate to shot! (pink -> red)
	int destTile = sourceTile;

	if (sourceTile >= 3 && sourceTile <= 15) destTile = sourceTile + 8 * 16;
	if (sourceTile >= 16 && sourceTile <= 31) destTile = sourceTile + 12 * 16;
	if (sourceTile >= 96 && sourceTile <= 111) destTile = sourceTile + 8 * 16;
	if (sourceTile == 2)  destTile = 153;
	if (sourceTile == 38) destTile = 154;
	if (sourceTile == 40) destTile = 155;
	if (sourceTile == 39) destTile = 154;
	if (sourceTile == 37) destTile = 156;
	if (sourceTile == 130) destTile = 157;
	if (sourceTile == 112) destTile = 158;
	if (sourceTile == 113) destTile = 159;

	return destTile;
}

void BeastDrawZSprite(int index, int zPos, int tile, int tileX, int tileY) {
	
	// Biting
	if (gBeasts1[index].State == BeastStateBiting) {
		TileDrawCharPos(BeastGetTile(index, gBeast1SettingsBiting.TilesZ5[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
		return;
	}

	// Dead
	if (gBeasts1[index].State == BeastStateDead) {
		if (zPos == 0) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsDying.TilesZ0[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
		if (zPos == 1) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsDying.TilesZ1[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
		if (zPos == 2) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsDying.TilesZ2[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
		if (zPos == 3) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsDying.TilesZ3[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
		if (zPos == 4) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsDying.TilesZ4[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
		return;
	}

	// Walking
	if (zPos == 0) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsWalking.TilesZ0[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
	if (zPos == 1) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsWalking.TilesZ1[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
	if (zPos == 2) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsWalking.TilesZ2[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
	if (zPos == 3) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsWalking.TilesZ3[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
	if (zPos == 4) TileDrawCharPos(BeastGetTile(index, gBeast1SettingsWalking.TilesZ4[gBeasts1[index].AnimationFrame][tile]), tileX, tileY);
}


void BeastDraw(int index) {

	// Stagger the intial beasts
	if (gBeasts1[index].InitialDelay > 0) return;

	int tileZ = gBeasts1[index].zPos;
	int tileX = gBeasts1[index].xPos,
		tileXCenterOffset = gBeast1SettingsWalking.ZArrayWidths[tileZ] / 2;

	int tileY = BeastGetYpos(index, tileZ);

	for (int tile = 0; tile < gBeast1SettingsWalking.ZArrayLengths[tileZ]; tile++)
	{
		// Draw row of tiles
		BeastDrawZSprite(index, tileZ, tile, tileX - tileXCenterOffset, tileY);

		tileX++;
		// wrap to next row
		if ((tileX - gBeasts1[index].xPos) == gBeast1SettingsWalking.ZArrayWidths[tileZ]) {
			tileX = gBeasts1[index].xPos;
			tileY++;
		}
	}
}