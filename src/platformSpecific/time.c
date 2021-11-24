#define FRAME_RATE 60
int gTimeInitialised = 0;

typedef struct {

	int Frame, WaveStartTime, WaveTime, Remaining, RemainingAfterWaveComplete, SinceLevelStarted, HiddenTime;
	double MsElapsedSinceLastFrame;
	unsigned int IsPaused, BonusAdded;
} timeStruct;

timeStruct g_Time = {
	.Frame=0, 
  	 //.WaveStartTime = START_TIME, .Remaining = START_TIME, 
	.HiddenTime=0,
	.MsElapsedSinceLastFrame=0,
	.IsPaused = false, .BonusAdded = false
};

void InitialiseTimer() {
	sceRtcGetCurrentTick(&g_VitaTime.Tick);
	g_VitaTime.LastTick = g_VitaTime.Tick.tick; 
	gTimeInitialised = 1;
}

void TimeWaitForNextFrame() {
	
	// return;
	if(!gTimeInitialised) InitialiseTimer();
	
	int tickChange = 0;
	//while(tickChange < TICKS_PER_FRAME) {
	while(tickChange < 16666) {
		sceRtcGetCurrentTick(&g_VitaTime.Tick);
		tickChange = g_VitaTime.Tick.tick - g_VitaTime.LastTick;
	}
	g_VitaTime.LastTick = g_VitaTime.Tick.tick;
	g_Time.MsElapsedSinceLastFrame = (int)(tickChange / 1000);	
}