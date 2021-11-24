#include "platformSpecific/includeFiles.c"
#include "platformSpecific/graphics.c"
#include "platformSpecific/sound.c"
#include "platformSpecific/input.c"
#include "platformSpecific/time.c"


#include "game.c"

#include "rand.c"
#include "collisions.c"
#include "tiles.c"
#include "background.c"
#include "gun.c"
#include "beast1.c"
#include "screenText.c"
#include "processFrame.c"




int main() {



    GraphicsInitialise();
    //IntroLoadingScreen();
    InputInitialise();
    BeastsInitialise();
    SoundInitialise();

    // gGame.State = GameStatePreIntro;


    while (!gFinished) {
        ProcessFrame();
        TimeWaitForNextFrame();
    }

    return 0;
}