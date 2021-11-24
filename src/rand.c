
int randMinMax(unsigned int min, unsigned int max) {
	int range = max - min;
	return rand() % range + min;
}

float randMinMaxFloat(float min, float max) {
	int range = (int)(max * 100) - (int)(min * 100);
	return (float)(rand() % range + (min * 100))/ 100.0f;
}