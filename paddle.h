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
        static constexpr float RESIZE_RATIO = 0.2;
        static constexpr float MARGIN = 30.0f;

        int width = PADDLE_WIDTH;
        int height = PADDLE_HEIGHT;
        bool isRightSide;

        Paddle(Vec2 position, int red, int green, int blue, bool isRight);

        void Draw(SDL_Renderer* renderer);

        void Resize(int windowWidth, int windowHeight);

        Vec2 position;

        SDL_FRect rect{};
};

#endif