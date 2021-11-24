void InitialiseFonts() {
	g_VitaFont = vita2d_load_font_file("app0:data/akaDylan.ttf");
}

int getTextWidth(unsigned int size, const char* text) {
	// al_get_fon
	return vita2d_font_text_width(g_VitaFont, size, text);
}

int getTextXCentered(unsigned int size, const char* text) {
	int fontWidth = getTextWidth(size, text);
	return (SCREEN_WIDTH / 2) - (fontWidth / 2);
}

void pulsateText(textStruct *settings) {

	if (settings->initialSize == 0) settings->initialSize = settings->size;

	g_Text.FontSkipFrame++;
	if (g_Text.FontSkipFrame == g_Text.FontSkipFrames) {

		if (settings->size == settings->initialSize + 4) g_Text.FontGrowth = -1;
		if (settings->size == settings->initialSize - 4) g_Text.FontGrowth = 1;

		settings->size += g_Text.FontGrowth;
		// -1 = centered
		if(settings->xPos != -1) settings->xPos -= g_Text.FontGrowth;
		if(settings->yPos != -1) settings->yPos -= g_Text.FontGrowth;

		g_Text.FontSkipFrame = 0;
	}
}

///////////////////////////////////////////////////////
void CycleTextColours(textStruct* text) {
	text->g += 5;
	text->b += 5;
	if (text->g > 140) text->g = 50;
	if (text->b > 140) text->b = 50;
}


int GetTextXCentered(textStruct* settings, const char* text) {
	return getTextXCentered(settings->size, text);
}


void DrawText(textStruct *settings, const char *text) {
	
	// Vita 2D draws the font with yPos at the bottom
	int yPos = settings->yPos + settings->size;
	int xPos = settings->xPos == -1 ? getTextXCentered(settings->size, text) : settings->xPos;

	int shc[4] = { FONT_COLOUR_SHADOW, 255},
		olc[4] = { FONT_COLOUR_3, 255},
		shadowColour  = RGBA8(shc[0],shc[1],shc[2],shc[3]),
		outlineColour = RGBA8(olc[0],olc[1],olc[2],olc[3]);
	
	if(settings->style == FONT_STYLE_SHADOW) {  
		int shadowOffset = settings->size <= FONT_SIZE_SMALL ? FONT_SHADOW_OFFSET_SMALL : FONT_SHADOW_OFFSET;
		vita2d_font_draw_text(g_VitaFont, xPos + shadowOffset, yPos + shadowOffset,
							  shadowColour, settings->size, text);		
	}
	
	if(settings->style == FONT_STYLE_OUTLINE) {  
		int outlineWidth = 1;
		vita2d_font_draw_text(g_VitaFont, xPos-outlineWidth, yPos-outlineWidth,	outlineColour, settings->size, text);		
		vita2d_font_draw_text(g_VitaFont, xPos,   			 yPos-outlineWidth, outlineColour, settings->size, text);		
		vita2d_font_draw_text(g_VitaFont, xPos+outlineWidth, yPos-outlineWidth, outlineColour, settings->size, text);	
		vita2d_font_draw_text(g_VitaFont, xPos-outlineWidth, yPos, 				outlineColour, settings->size, text);			
		vita2d_font_draw_text(g_VitaFont, xPos+outlineWidth, yPos, 				outlineColour, settings->size, text);	
		vita2d_font_draw_text(g_VitaFont, xPos-outlineWidth, yPos+outlineWidth, outlineColour, settings->size, text);		
		vita2d_font_draw_text(g_VitaFont, xPos,  			 yPos+outlineWidth, outlineColour, settings->size, text);		
		vita2d_font_draw_text(g_VitaFont, xPos+outlineWidth, yPos+outlineWidth, outlineColour, settings->size, text);		
	}	
	
	
	vita2d_font_draw_text(g_VitaFont, xPos, yPos, RGBA8(settings->r, settings->g, settings->b, 255), settings->size, text);

	if (settings->isPulsating) pulsateText(settings);	

}						  