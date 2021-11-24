enum { GameStatePreIntro, GameStateGame, GameStateIntro, GameStateOver};

int gFinished = 0;

typedef struct {
	int State, Score, Health, Ammo, MaxAmmo,
		HealthBonus, HealthBonusFlashTextShowing,
		HealthBonusFlashFrame, HealthBonusFlashFramesCount, HealthBonusFlashFrameCount,
		HealthBonusLastScore;
} GameStruct;


GameStruct gGame = { .Health = 100, .Ammo = 6, .MaxAmmo = 6,
	.HealthBonus = 1000, .HealthBonusFlashFramesCount = 120, .HealthBonusFlashFrameCount = 10 
};

void GameInitialise() {
	gGame.Health = 100;
	gGame.Ammo = 6;
	gGame.Score = 0;
	gGame.HealthBonusLastScore = 0;
}

// Health Bonus Reached
void GameCheckHealthBonus() {
	if (gGame.Score == 0) return;
	if (gGame.Score == gGame.HealthBonusLastScore) return;
	if (gGame.Score % gGame.HealthBonus != 0) return;
	gGame.HealthBonusLastScore = gGame.Score;
	gGame.HealthBonusFlashFrame = gGame.HealthBonusFlashFramesCount;
	gGame.HealthBonusFlashTextShowing = 1;
	gGame.Health += 100;
}

// Health Bonus - Flash Message
void GameHealthBonusFlashTextAdvance() {
	gGame.HealthBonusFlashFrame--;
	if (gGame.HealthBonusFlashFrame % gGame.HealthBonusFlashFrameCount == 0) {
		gGame.HealthBonusFlashTextShowing = !gGame.HealthBonusFlashTextShowing;
	}
}