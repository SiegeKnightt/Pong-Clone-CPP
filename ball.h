#ifndef BALL_H
#define BALL_H

#include <SDL3/SDL.h>

class Vec2 {
    public:
        // Constructors
        Vec2() : x(0.0f), y(0.0f) {}
        Vec2(float x, float y) : x(x), y(y) {}

        float x;
        float y;
};

class Ball {
    public:
        Ball(Vec2 position);

        void Draw(SDL_Renderer* renderer);

        Vec2 position;

        SDL_FRect rect{};
};

#endif