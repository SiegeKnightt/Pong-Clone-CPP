#ifndef BALL_H
#define BALL_H

#include <SDL3/SDL.h>
#include <vec2.h>

class Ball {
    public:
        static const int BALL_WIDTH = 15;
        static const int BALL_HEIGHT = 15;

        Ball(Vec2 position);

        void Draw(SDL_Renderer* renderer);

        Vec2 position;

        SDL_FRect rect{};
};

#endif