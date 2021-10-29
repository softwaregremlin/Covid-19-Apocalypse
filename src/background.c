#define TILES_MOUNTAIN_HEIGHT 3

int TilesBackground[] =
{ 162, 163, 164, 165, 177, 178, 179, 180, 180, 180, 180, 180, 180, 144, 145, 146, 147, 148, 149, 149, 160, 161, 161, 161, 161, 161 };

int TilesMountainRows[TILES_MOUNTAIN_HEIGHT][TILES_X_COUNT] =
{ {0, 192, 193, 0, 0, 192, 193, 0, 0, 192, 193, 0, 0, 192, 193, 0, 0, 192, 193, 0,
   0, 192, 193, 0, 0, 192, 193, 0, 0, 192, 193, 0, 0, 192, 193, 0, 0, 192, 193, 0} ,
  {192, 194, 194, 193, 192, 194, 194, 193,192, 194, 194, 193,192, 194, 194, 193, 192, 194, 194, 193,
   192, 194, 194, 193, 192, 194, 194, 193,192, 194, 194, 193,192, 194, 194, 193, 192, 194, 194, 193},
  { 194,194,194,195, 194,194,194,195, 194,194,194,195, 194,194,194,195, 194,194,194,195,
    194,194,194,195, 194,194,194,195, 194,194,194,195, 194,194,194,195, 194,194,194,195 }
};
int TilesMountainYRow = 10;

int BackgroundFrame = 0, BackgroundIsScrolling = 0, BackgroundScrollSpeed = 15;


void BackgroundScrollMountains() {
	BackgroundFrame++;
	BackgroundIsScrolling = (BackgroundFrame == BackgroundScrollSpeed);
	if (!BackgroundIsScrolling) return;
	BackgroundFrame = 0;

	for (int y = 0; y < TILES_MOUNTAIN_HEIGHT; y++) {

		int firstTile = TilesMountainRows[y][0];
		for (int x = 0; x < TILES_X_COUNT - 1; x++) {
			TilesMountainRows[y][x] = TilesMountainRows[y][x + 1];
		}
		TilesMountainRows[y][TILES_X_COUNT - 1] = firstTile;
	}
}

void BackgroundDraw() {

	//for (int y = TilesBackgroundTerrainStart; y < TILES_Y_COUNT; y++) {
	for (int y = 0; y < TILES_Y_COUNT; y++) {
		TileDrawRow(TilesBackground[y], y);
	}

	for (int y = 0; y < TILES_MOUNTAIN_HEIGHT; y++) {
		TileDrawArrayRow(TilesMountainRows[y], y + TilesMountainYRow);
	}
	BackgroundScrollMountains();
}