#include <ball.h>

Ball::Ball(Vec2 position, Vec2 vel) : position(position), velocity(vel) {

    rect.w = BALL_WIDTH;
    rect.h = BALL_HEIGHT;
} 

void Ball::Draw(SDL_Renderer* renderer) {

    rect.x = position.x;
    rect.y = position.y;

    SDL_RenderFillRect(renderer, &rect);
}

int Ball::Update(int windowWidth, int windowHeight) {

    // Update position with new velocity
    position.x += velocity.x;
    position.y += velocity.y;

    // Check top/bottom collison
    if (position.y < 0) {

        position.y = 0;
        velocity.y *= -1;
    }
    else if ((position.y + BALL_HEIGHT) > windowHeight) {

        position.y =  windowHeight - BALL_HEIGHT;
        velocity.y *= -1;
    }

    // Check left/right collsion
    if (position.x < 0) {

        // Score go up for paddle 2
        position.x = (windowWidth / 2) - (Ball::BALL_WIDTH / 2);
        position.y = (windowHeight / 2) - (Ball::BALL_HEIGHT / 2);

        velocity.x = -0.1;
        velocity.y = 0.0;

        return 2;
    }
    else if ((position.x + BALL_WIDTH) > windowWidth) {

        // Score go up for paddle 1
        position.x = (windowWidth / 2) - (Ball::BALL_WIDTH / 2);
        position.y = (windowHeight / 2) - (Ball::BALL_HEIGHT / 2);

        velocity.x = 0.1;
        velocity.y = 0.0;

        return 1;
    }
}