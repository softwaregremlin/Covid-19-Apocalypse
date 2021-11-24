#define SCREEN_TEXT_SCORE_LENGTH 6
#define SCREEN_TEXT_HEALTH_LENGTH 3
int ScreenTextScore[] = { 83, 67, 79, 82, 69, 0, 0,0,0,0,0,0,0,0 },
    ScreenTextHealth[] = { 72, 69, 65, 76, 84, 72, 0, 0,0,0 },
    ScreenTextHealthBonus[] = { 72, 69, 65, 76, 84, 72, 0, 66, 79, 78, 85, 83, 33 },
    ScreenTextAmmo[] = { 196, 196, 196, 196, 196, 196 },
    ScreenTextReload[] = { 82, 69, 76, 79, 65, 68, 33},
    ScreenTextReLoading[] = { 82, 69, 76, 79, 65, 68, 73, 78, 71 };


void ScreenTextRenderNumbers() {
    
    char numberString[SCREEN_TEXT_SCORE_LENGTH + 1];

    // Score
    sprintf(numberString, "%06d", gGame.Score);
    for (int cc = 0; cc < SCREEN_TEXT_SCORE_LENGTH; cc++) {
        ScreenTextScore[cc + 6] = numberString[cc];
    }

    // Health
    sprintf(numberString, "%03d", gGame.Health);
    for (int cc = 0; cc < SCREEN_TEXT_HEALTH_LENGTH; cc++) {
        ScreenTextHealth[cc + 7] = numberString[cc];
    }
}

void ScreenTextRenderAmmo() {
    int blankAmmoTiles = gGame.MaxAmmo - gGame.Ammo, aa;
    for (aa = 0; aa < 6; aa++) ScreenTextAmmo[aa] = 196;
    for (aa = 0; aa < blankAmmoTiles; aa++) ScreenTextAmmo[aa] = 0;
}

void ScreenTextDraw() {

    int row = 1;

    ScreenTextRenderNumbers();
	TileDrawArrayRowSection(ScreenTextScore, row, 12, 0);

	TileDrawArrayRowSection(ScreenTextHealth, row, 10, 30);
    // Flash the Health Bonus message
    if (gGame.HealthBonusFlashFrame > 0) {
        if (gGame.HealthBonusFlashTextShowing) {
            TileDrawArrayRowSection(ScreenTextHealthBonus, row + 1, 13, 27);
        }
        GameHealthBonusFlashTextAdvance();
    }
    

    ScreenTextRenderAmmo();
    TileDrawArrayRowSection(ScreenTextAmmo, row, 6, 17);
    

    if(gGun.State == GunStateEmpty) {
        // Flash the RELOAD! message
        if (GunFlashTextShowing()) TileDrawArrayRowSection(ScreenTextReload, row, 7, 17);
        GunFlashTextAdvance();
    }

    if (gGun.State == GunStateReloading) {
        if (GunFlashTextShowing()) TileDrawArrayRowSection(ScreenTextReLoading, row + 1, 9, 17);
        GunFlashTextAdvance();
        GunReloadingAdvance();
    }



}