#define GRAPHICS_IMAGE_COUNT 2
#define GRAPHICS_WINDOW_WIDTH 960 //640
#define GRAPHICS_WINDOW_HEIGHT 544 //480

#define GRAPHICS_TILE_SIZE 8
#define GRAPHICS_TILES_X_COUNT 40
#define GRAPHICS_TILES_Y_COUNT 25

int gBypassLoading = 0;

typedef struct {
	int WindowWidth, WindowHeight;
	float ScreenScaleX, ScreenScaleY;
	float TileScaleX, TileScaleY;
} GraphicsSettingsStruct;

/////////////////////////
typedef struct {
	int Width, Height, RegionX, RegionY;
	float Scale, ScaleX, ScaleY;
} GraphicsImageStruct;


GraphicsSettingsStruct gGraphicsSettings = 
  { .WindowWidth = GRAPHICS_WINDOW_WIDTH, .WindowHeight = GRAPHICS_WINDOW_HEIGHT, .ScreenScaleX = 1.23,  .ScreenScaleY = 1.0 };
//GraphicsSettingsStruct gGraphicsSettings = { .WindowWidth = 640, .WindowHeight = 480, .ScreenScaleX = 1.0,  .ScreenScaleY = 1.0 };
GraphicsImageStruct gGraphicsImages[GRAPHICS_IMAGE_COUNT] = {
	{.Width = 128, .Height = 128, .ScaleX = 2.0, .ScaleY = 2.4 },
	{.Width = 24, .Height = 16, .ScaleX = 2.0, .ScaleY = 2.4 }
};

void GraphicsLoadImage(vita2d_texture ** image, const char *filename) {
	
	char folderAndFile[50] = "app0:data/images/";
	strcat(folderAndFile, filename);
	
	vita2d_wait_rendering_done(); 
	vita2d_free_texture(*image);	
	*image = vita2d_load_PNG_file(folderAndFile);
}

void GraphicsInitialise() {

	sceKernelPowerTick(SCE_KERNEL_POWER_TICK_DISABLE_AUTO_SUSPEND);
	sceKernelPowerTick(SCE_KERNEL_POWER_TICK_DISABLE_OLED_OFF);

	// g_Game.ScaleFactorDevice = (float)SCREEN_HEIGHT / (float)MAX_DEVICE_HEIGHT;

	gGraphicsSettings.TileScaleX = (float)gGraphicsSettings.WindowWidth / (float)(GRAPHICS_TILES_X_COUNT * GRAPHICS_TILE_SIZE);
	gGraphicsSettings.TileScaleY = (float)gGraphicsSettings.WindowHeight / (float)(GRAPHICS_TILES_Y_COUNT * GRAPHICS_TILE_SIZE);	
	
	vita2d_init();
	vita2d_set_clear_color(RGBA8(0, 0, 0, 255));
	
	GraphicsLoadImage(&g_GraphicsImage0, "tiles.png");
	GraphicsLoadImage(&g_GraphicsImage1, "crosshairs.png");
	// GraphicsLoadImage(&g_GraphicsCollisionRec, "collisionRec.png");	
}

void GraphicsBlitImage(vita2d_texture* image, float x, float y) {
	vita2d_draw_texture(image, x, y);
}

void GraphicsBlitImageRegion(vita2d_texture* image, float xPos, float yPos,
	float regionX, float regionY, float regionWidth, float regionHeight,
	float xScale, float yScale) {
	
	vita2d_draw_texture_part_scale(image,
		xPos, yPos, regionX, regionY, regionWidth, regionHeight, xScale, yScale);
}




void GraphicsStartDrawing() {
	vita2d_start_drawing();
	vita2d_clear_screen();
}

void GraphicsStopDrawing() {
	vita2d_end_drawing();
	vita2d_swap_buffers();
}





void BlitImageRegionTinted(vita2d_texture* image, float xPos, float yPos,
	float regionX, float regionY, float regionWidth, float regionHeight,
	float xScale, float yScale,
	int r, int g, int b) {
	
	vita2d_draw_texture_tint_part_scale(image,
		xPos, yPos, regionX, regionY, regionWidth, regionHeight, xScale, yScale, RGBA8(r,g,b,255));
}

int GetImageHeight(vita2d_texture* image) {
	return vita2d_texture_get_height(image);
}

int GetImageWidth(vita2d_texture* image) {
	return vita2d_texture_get_width(image);
}

void GraphicsDrawCollisionRectangle(float x, float y, float width, float height) {
	float xScale = width / 16.0, yScale = height / 16.0;

	// printf("%.2f\n, %.2f\n", xScale, yScale);
	GraphicsBlitImageRegion(g_GraphicsImage0, x, y, 112, 112, 16, 16, xScale, yScale);
}
