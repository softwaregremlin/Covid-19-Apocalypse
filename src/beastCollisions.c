
int BeastBulletCollision(int index, int rectangleIndex) {

	if (gGame.Ammo == 0) return 0;

	float tileScaleX = (float)gGraphicsSettings.WindowWidth / (float)(TILES_X_COUNT * TILE_SIZE),
		tileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(TILES_Y_COUNT * TILE_SIZE);
	int tileZ = gBeasts1[index].zPos;
	int tileX = gBeasts1[index].xPos + gBeast1SettingsWalking.CollisionRec1TileXOffset[rectangleIndex][tileZ],
		tileXCenterOffset = gBeast1SettingsWalking.ZArrayWidths[tileZ] / 2,
		tileXCount = gBeast1SettingsWalking.CollisionRec1TileXWidth[rectangleIndex][tileZ],
		tileYCount = gBeast1SettingsWalking.CollisionRec1TileYHeight[rectangleIndex][tileZ];
	int tileY = BeastGetYpos(index, tileZ) + gBeast1SettingsWalking.CollisionRec1TileYOffset[rectangleIndex][tileZ];

	tileX -= tileXCenterOffset;


	float xPixel = (float)tileX * TILE_SIZE * tileScaleX,
		yPixel = (float)tileY * TILE_SIZE * tileScaleY,
		widthPixel = TILE_SIZE * tileScaleX * tileXCount,
		heightPixel = TILE_SIZE * tileScaleY * tileYCount;

	return InRectangle(gInputPointerX, gInputPointerY, xPixel, yPixel, widthPixel, heightPixel);

}


int BeastBulletCollisions(int index) {
	return BeastBulletCollision(index, 0) || BeastBulletCollision(index, 1);
}

void BeastDrawCollisionRectangle(int index, int recIndex) {
	return;
	float tileScaleX = (float)gGraphicsSettings.WindowWidth / (float)(TILES_X_COUNT * TILE_SIZE),
		  tileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(TILES_Y_COUNT * TILE_SIZE);

	int tileZ = gBeasts1[index].zPos;
	int tileX = gBeasts1[index].xPos + gBeast1SettingsWalking.CollisionRec1TileXOffset[recIndex][tileZ],
		tileXCenterOffset = gBeast1SettingsWalking.ZArrayWidths[tileZ] / 2,
		tileXCount = gBeast1SettingsWalking.CollisionRec1TileXWidth[recIndex][tileZ],
		tileYCount = gBeast1SettingsWalking.CollisionRec1TileYHeight[recIndex][tileZ];
	int tileY = BeastGetYpos(index, tileZ) + gBeast1SettingsWalking.CollisionRec1TileYOffset[recIndex][tileZ];

	tileX -= tileXCenterOffset;



	float xPixel = (float)tileX * TILE_SIZE * tileScaleX,
		yPixel = (float)tileY * TILE_SIZE * tileScaleY,
		widthPixel = TILE_SIZE * tileScaleX * tileXCount,
		heightPixel = TILE_SIZE * tileScaleY * tileYCount;

	GraphicsDrawCollisionRectangle(xPixel, yPixel, widthPixel, heightPixel);

}