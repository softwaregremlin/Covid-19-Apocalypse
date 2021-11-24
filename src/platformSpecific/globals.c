// Display
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544
#define true 1
#define false 0

// Images
typedef struct {
	vita2d_texture* Background[4];
	vita2d_texture* Player;
	vita2d_texture* Enemy[8];
	vita2d_texture* Rock;
	vita2d_texture* Band;
	vita2d_texture* PauseBackground;
} imageStruct;

imageStruct g_Images;


vita2d_texture* g_GraphicsImage0;
vita2d_texture* g_GraphicsImage1;

int gInputPointerX, gInputPointerY, gInputFire;

// Timing
#define TICKS_PER_FRAME 1000000 / FRAME_RATE
typedef struct { SceRtcTick Tick; uint64_t   LastTick;  } vitaTimeStruct;
vitaTimeStruct g_VitaTime;

// Input
SceCtrlData g_VitaPad;
#define MIN_ANALOG_STICK_THRESHOLD 50
#define MAX_ANALOG_STICK_THRESHOLD 205

// Saved data paths
/*
dataPathsStruct g_DataPaths = {
	.Folder = "ux0:data/aotlmc",
	.HighScore = "ux0:data/aotlmc/hi", .Level = "ux0:data/aotlmc/lev", .MaxLevel = "ux0:data/aotlmc/maxlev",
	.Log = "ux0:data/aotlmc/log", .WaveTime = "ux0:data/aotlmc/wt", .CheatMode = "ux0:data/aotlmc/ch"
};	
*/
	
// Sound
int gSoundCovid;
//vitaWav *gSoundCovid;
vitaWav *gSoundShot;
vitaWav *gSoundReload;
vitaWav *gSoundEmpty;
vitaWav *gSoundBite1;
vitaWav *gSoundBite2;
vitaWav *gSoundKill;

//Font
vita2d_font *g_VitaFont;
