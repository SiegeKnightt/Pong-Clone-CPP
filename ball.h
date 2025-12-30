#ifndef BALL_H
#define BALL_H

#include <SDL3/SDL.h>
#include <vec2.h>

class Ball {
    public:
        static const int BALL_WIDTH = 15;
        static const int BALL_HEIGHT = 15;
        static constexpr float BALL_VELOCITY_X = -0.1;
        static constexpr float BALL_VELOCITY_Y = -0.1;

        Vec2 position;
        Vec2 velocity = Vec2(BALL_VELOCITY_X, BALL_VELOCITY_Y);

        Ball(Vec2 position, Vec2 vel);

        void Draw(SDL_Renderer* renderer);

        void Update(int windowWidth, int windowHeight);

        SDL_FRect rect{};
};

#endif