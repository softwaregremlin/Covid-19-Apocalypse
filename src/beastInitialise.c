void BeastInitialise(int index) {
	gBeasts1[index].State = BeastStateWalking;
	gBeasts1[index].xPos = randMinMax(0, 40);
	gBeasts1[index].yPos = 12;
	gBeasts1[index].zPos = 0;
	gBeasts1[index].Hits = 0;
	
}

void BeastsInitialise() {
	// Seed our random numbers
	srand(time(NULL));

	for (int bb = 0; bb < BEASTS_MAX; bb++) {
		BeastInitialise(bb);
		gBeasts1[bb].InitialDelay = bb * 60;
	}
}