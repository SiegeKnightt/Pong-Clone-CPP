#include <paddle.h>

Paddle::Paddle(Vec2 position, int red, int green, int blue) : position(position) {

    rect.w = PADDLE_WIDTH;
    rect.h = PADDLE_HEIGHT;

    r = red;
    g = green;
    b = blue;
    a = 255;
} 

void Paddle::Draw(SDL_Renderer* renderer) {

    // Have to cast to an int since position is a float
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}