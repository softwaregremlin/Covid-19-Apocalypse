/*
#include <math.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/sysmem.h>
#include <psp2/kernel/clib.h>
#include <psp2/io/fcntl.h>
#include <psp2/audioout.h>
#include <psp2/appmgr.h>

#include <vorbis/vorbisfile.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
*/
// #include "audio.h"

void SoundPlay(vitaWav *wav) {
	vitaWavPlay(wav);
}

void SoundPlayLoop(vitaWav *wav) {
	vitaWavLoop(wav, 1);
	vitaWavPlay(wav);
}

void SoundPlayStop(vitaWav *wav) {
	vitaWavStop(wav);
}


void SoundInitialise() {
	vitaWavInit();
	//gSoundCovid  = vitaWavLoadVorbis("app0:data/sounds/covid.ogg");
	gSoundCovid  = soundLoadBackgroundMusic("app0:data/sounds/covid.ogg");
	gSoundShot   = vitaWavLoadVorbis("app0:data/sounds/shot.ogg");
	gSoundReload = vitaWavLoadVorbis("app0:data/sounds/reload.ogg");
	gSoundEmpty  = vitaWavLoadVorbis("app0:data/sounds/empty.ogg");
	gSoundBite1  = vitaWavLoadVorbis("app0:data/sounds/bite1.ogg");
	gSoundBite2  = vitaWavLoadVorbis("app0:data/sounds/bite2.ogg");
	gSoundKill   = vitaWavLoadVorbis("app0:data/sounds/kill.ogg");

	// SoundPlayLoop(gSoundCovid);
	//soundStartBackgroundMusicLoop();
}

void SoundPlayShot()   { SoundPlay(gSoundShot);   }
void SoundPlayEmpty()  { SoundPlay(gSoundEmpty);  }
void SoundPlayReload() { SoundPlay(gSoundReload); }
void SoundPlayKill()   { SoundPlay(gSoundKill);   }
void SoundPlayBite1()  { SoundPlay(gSoundBite1);  }
void SoundPlayBite2()  { SoundPlay(gSoundBite2);  }

void SoundPlayBackgroundMusic() {
	soundStartBackgroundMusicLoop();
}