#include <paddle.h>

Paddle::Paddle(int red, int green, int blue, bool isRight) {

    rect.w = PADDLE_WIDTH;
    rect.h = PADDLE_HEIGHT;

    r = red;
    g = green;
    b = blue;
    a = 255;

    isRightSide = isRight;
} 

void Paddle::Draw(SDL_Renderer* renderer) {

    rect.x = position.x;
    rect.y = position.y;

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}

void Paddle::Resize(int windowWidth, int windowHeight) {

    height = windowHeight * RESIZE_RATIO;

    position.y = (windowHeight / 2) - (height / 2);

    if (isRightSide) {

        position.x = windowWidth - 50 - width;
    }
    else {

        position.x = MARGIN;
    }

    rect.h = static_cast<int>(height);
}