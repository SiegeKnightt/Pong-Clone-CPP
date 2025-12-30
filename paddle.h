#ifndef PADDLE_H
#define PADDLE_H

#include <SDL3/SDL.h>
#include <vec2.h>

class Paddle {
    private:
        int r;
        int g;
        int b;
        int a;
    public:
        static const int PADDLE_WIDTH = 15;
        static const int PADDLE_HEIGHT = 90;
        
        Paddle(Vec2 position, int red, int green, int blue);

        void Draw(SDL_Renderer* renderer);

        Vec2 position;

        SDL_FRect rect{};
};

#endif