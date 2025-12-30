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

        position.x = windowWidth - MARGIN - width;
    }
    else {

        position.x = MARGIN;
    }

    rect.h = static_cast<int>(height);
}

void Paddle::Update(int windowHeight) {

    const bool* state = SDL_GetKeyboardState(NULL);

    // Check for paddle movement
    if (!isRightSide) {

        if (state[SDL_SCANCODE_W]) {

            velocity = -0.1;
        }
        else if (state[SDL_SCANCODE_S]) {

            velocity = 0.1;
        }
        else {

            velocity = 0.0;
        }
    }
    else {

        if (state[SDL_SCANCODE_UP]) {

            velocity = -0.1;
        }
        else if (state[SDL_SCANCODE_DOWN]) {

            velocity = 0.1;
        }
        else {

            velocity = 0.0;
        }
    }

    // Update position with new velocity
    position.y += velocity;

    // Boundary checker
    if (position.y < 0) {

        position.y = 0;
    }
    else if ((position.y + height) > windowHeight) {

        // Have to subtract the height of the paddle or it gets stuck out of bounds
        position.y = windowHeight - height;
    }
}