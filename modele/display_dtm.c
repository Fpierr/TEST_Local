#include "main.h"

/**
 * displayDTM - Display the Digital Terrain Model (DTM) using SDL rendering.
 *
 * @renderer: The SDL renderer to use for rendering.
 * @dtm: The array containing DTM data.
 */
void displayDTM(SDL_Renderer *renderer, int dtm[DTM_WIDTH][DTM_HEIGHT])
{
	int rectWidth = SCREEN_WIDTH / DTM_WIDTH;
	int rectHeight = SCREEN_HEIGHT / DTM_HEIGHT;
	int x, y;
	SDL_Rect rect;

	for (y = 0; y < DTM_HEIGHT; ++y)
	{
		for (x = 0; x < DTM_WIDTH; ++x)
		{
			/* Calculate color based on height value */
			int height = dtm[x][y];
			int color = 255 - height; /* Example, adjust based on your requirements */

			/* Set the color */
			SDL_SetRenderDrawColor(renderer, color, color, color, 255);

			/* Draw a rectangle */
			rect = {x * rectWidth, y * rectHeight, rectWidth, rectHeight};
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

