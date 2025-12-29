#include "renderer.h"

void DrawGame(SDL_Renderer* renderer, int width, int height) {
    
    // Clear the window background to black
    // R,G,B
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
    SDL_RenderClear(renderer);

    // Draw Net
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
    for (int y = 0; y < height; y++) {

        // Leave a gap every 5 pixels
        if (y % 5) {

            // Width / 2 to get the middle of the screen
            SDL_RenderPoint(renderer, (float)width / 2.0, (float)y);
        }
    }

    // Draw paddles?

    // Presents the backbuffer to prevent player from seeing things being drawn
    SDL_RenderPresent(renderer);
}