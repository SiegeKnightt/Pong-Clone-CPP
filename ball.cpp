#include <ball.h>

Ball::Ball(Vec2 position) :position(position) {

    rect.w = BALL_WIDTH;
    rect.h = BALL_HEIGHT;
} 

void Ball::Draw(SDL_Renderer* renderer) {

    rect.x = position.x;
    rect.y = position.y;

    SDL_RenderFillRect(renderer, &rect);
}