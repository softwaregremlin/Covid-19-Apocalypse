#define TILE_SIZE 8
#define TILE_SET_WIDTH 16
#define TILES_X_COUNT 40
#define TILES_Y_COUNT 25
//#define TILES_MOUNTAIN_HEIGHT 3


int TilesCrossHairs[] = { 144 };



int TilesGun[2][5] = { {0, 114,116, 115,0 }, { 114,117, 116, 117, 115 } };





void TileDraw(int index, float x, float y) {
	
	int regionX = (index % TILE_SET_WIDTH) * TILE_SIZE,
		regionY = (index / TILE_SET_WIDTH) * TILE_SIZE;

	GraphicsBlitImageRegion(g_GraphicsImage0, x, y,
		regionX, regionY,
		TILE_SIZE, TILE_SIZE,
		gGraphicsSettings.TileScaleX, gGraphicsSettings.TileScaleY);
}

void TileDrawCharPos(int index, int xCol, int yRow) {
	float tileScaleX = (float)gGraphicsSettings.WindowWidth / (float)(TILES_X_COUNT * TILE_SIZE),
		  tileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(TILES_Y_COUNT * TILE_SIZE);
	TileDraw(index, xCol * TILE_SIZE * tileScaleX, (float)yRow * (float)TILE_SIZE * tileScaleY);
}


void TileDrawArrayRowSection(int* tileArray, int yRow, int tileLength, int xStartPos) {
	float tileScaleX = (float)gGraphicsSettings.WindowWidth / (float)(TILES_X_COUNT * TILE_SIZE),
		tileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(TILES_Y_COUNT * TILE_SIZE),
		yPos = (float)yRow * (float)TILE_SIZE * tileScaleY;

	for (int x = 0; x < tileLength; x++) {
		TileDraw(tileArray[x], (x + xStartPos)* TILE_SIZE * tileScaleX, yPos);
	}
}

// Row of the same tile across the screen
void TileDrawRow(int tileIndex, int yRow) {
	float tileScaleX = (float)gGraphicsSettings.WindowWidth  / (float)(TILES_X_COUNT * TILE_SIZE),
		  tileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(TILES_Y_COUNT * TILE_SIZE),
		  yPos = (float)yRow * (float)TILE_SIZE * tileScaleY;

	for (float x = 0; x < TILES_X_COUNT; x++) {
		TileDraw(tileIndex, x * TILE_SIZE * tileScaleX, yPos);
	}
}

// Row of the same tile across the screen
void TileDrawArrayRow(int* tileArray, int yRow) {
	TileDrawArrayRowSection(tileArray, yRow, TILES_X_COUNT,0);
}



