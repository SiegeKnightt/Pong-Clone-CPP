#ifndef SCORE_H
#define SCORE_H

#include <SDL3/SDL.h>
#include <SDL_ttf.h>

SDL_Texture* CreateScoreTexture(SDL_Renderer* renderer, TTF_Font* font, int sc1, int sc2);

#endif