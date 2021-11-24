
// Helper function
int Between(int value, int min, int max) {
	return value >= min && value <= max;
}

// Helper function
int InRectangle(int x, int y, int left, int top, int width, int height) {
	return Between(x, left, left + width) &&
		Between(y, top, top + height);
}