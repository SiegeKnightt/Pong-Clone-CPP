#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main(int argc, char* argv[]) {

    // Initialize SDL components
    SDL_Init(SDL_INIT_VIDEO);

    // Creates the game window
    SDL_Window* window = SDL_CreateWindow("Pong", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    // Creates the renderer for the game window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    bool running = true;

    // Game logic
    while (running) {

        SDL_Event event;

        // Process events in the window until the user exits the program
        while (SDL_PollEvent(&event)) {

            if (event.key.key == SDLK_ESCAPE || event.type == SDL_EVENT_QUIT) {

                running = false;
            }
        }

        // Clear the window to black
        // R,G,B
        SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Rendering will occur here
        
        // Presents the backbuffer
        SDL_RenderPresent(renderer);
    }
    
    // Cleanup SDL 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}