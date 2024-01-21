#include "main.h"

/**
 * main - Main function to initialize SDL and display Digital Terrain Modele
 *
 * Return: 0 on successful execution.
 */
int main(void)
{
	int dtm[DTM_WIDTH][DTM_HEIGHT], quit = 0;
	SDL_Event e;
	SDL_Renderer *renderer;

	SDL_Init(SDL_INIT_VIDEO);
	/* Initialize SDL window and renderer */
	SDL_Window *window = SDL_CreateWindow("DTM Viewer", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
		return (1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		return (1);
	}
	readDTMFromFile("/home/fanuel/TEST_Local/modele/dtm.txt", dtm);
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = 1;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); /* Clear the screen */
		SDL_RenderClear(renderer);
		displayDTM(renderer, dtm);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer); /* Cleanup code for SDL */
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
