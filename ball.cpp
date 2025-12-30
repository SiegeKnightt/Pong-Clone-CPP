#include <ball.h>

const int BALL_WIDTH = 15;
const int BALL_HEIGHT = 15;

Ball::Ball(Vec2 position) :position(position) {

    rect.w = BALL_WIDTH;
    rect.h = BALL_HEIGHT;
} 

void Ball::Draw(SDL_Renderer* renderer) {

    // Have to cast to an int since position is a float
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);

    SDL_RenderFillRect(renderer, &rect);
}