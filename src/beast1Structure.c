#define BEASTS_MAX 3

typedef struct {
    int TilesZ0[2][2],
        TilesZ1[2][6],
        TilesZ2[2][40],
        TilesZ3[2][176],
        TilesZ4[2][256],

        CollisionRec1TileXOffset[2][5],
        CollisionRec1TileXWidth[2][5],
        CollisionRec1TileYOffset[2][5],
        CollisionRec1TileYHeight[2][5],

        ZArrayLengths[6],
        ZArrayWidths[6],
        ZArrayHeights[6],

        HitCount,
        ScorePerBeast;

} Beast1SettingsStruct;


typedef struct {
    int TilesZ5[2][627], ZArrayLength, ZArrayWidth, ZArrayHeight;
} Beast1SettingsBitingStruct;



#include "beast1SettingsWalking.c"
#include "beast1SettingsDying.c"
#include "beast1SettingsBiting.c"


/////////////////////////////////////////////////////////////

enum { BeastStateWalking, BeastStateShot, BeastStateDead, BeastStateBiting };
enum { DirectionForward, DirectionBackward};


typedef struct {
    int xPos, yPos, zPos, State, 
        Frame, FrameShot, FrameDead, 
        InitialDelay,
        AnimationFrame, 
        Direction, Hits;
} Beast1;

//Beast1 gBeast1 = { .xPos = 20, .yPos = 12, .zPos = 0, 
//                   .State = BeastStateWalking, .Direction = DirectionForward };

Beast1 gBeasts1[BEASTS_MAX];
