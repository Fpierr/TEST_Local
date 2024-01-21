#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <SDL2/SDL.h>

/* Dimensions of the DTM */
#define DTM_WIDTH 800
#define DTM_HEIGHT 200
#define WATER_LEVEL 10

/* Screen dimensions */
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

int readDTMFromFile(const char *fileName, int dtm[DTM_WIDTH][DTM_HEIGHT]);
void displayDTM(SDL_Renderer *renderer, int dtm[DTM_WIDTH][DTM_HEIGHT]);

#endif  /* MAIN_H */
