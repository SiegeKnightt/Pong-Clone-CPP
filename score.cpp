#include <score.h>
#include <cstdio>

SDL_Texture* CreateScoreTexture(SDL_Renderer* renderer, TTF_Font* font, int sc1, int sc2) {

    char scoreBuf[16];
    snprintf(scoreBuf, sizeof(scoreBuf), "%d : %d", sc1, sc2);
    
    SDL_Color white = {255, 255, 255, 255};

    SDL_Surface* surface = TTF_RenderText_Blended(font, scoreBuf, 0, white);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    SDL_DestroySurface(surface);
    
    return texture;
}