#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>
#include <net.h>
#include <ball.h>
#include <paddle.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main(int argc, char* argv[]) {

    // Initialize SDL components
    SDL_Init(SDL_INIT_VIDEO);

    // Creates the game window
    SDL_Window* window = SDL_CreateWindow("Pong", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    // Creates the renderer for the game window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    bool running = true;

    int current_width = WINDOW_WIDTH;
    int current_height = WINDOW_HEIGHT; 

    // Create the ball and set it to the center of the screen
    Ball ball(Vec2((current_width / 2) - (Ball::BALL_WIDTH / 2), (current_height / 2) - (Ball::BALL_HEIGHT / 2)), Vec2(Ball::BALL_VELOCITY_X, Ball::BALL_VELOCITY_Y));

    // Create the paddles and set them to their appropriate positions 
    // Also set colors (p1 is red, p2 is blue)
    Paddle paddleOne(255, 0, 0, false);
    Paddle paddleTwo(0, 0 , 255, true);
    paddleOne.Resize(current_width, current_height);
    paddleTwo.Resize(current_width, current_height);

    SDL_Log("Paddle 1 height is %d", paddleOne.height);
    SDL_Log("Paddle 2 height is %d", paddleTwo.height);

    // Game logic
    while (running) {

        SDL_Event event;

        // Process events in the window until the user exits the program
        while (SDL_PollEvent(&event)) {

            if (event.key.key == SDLK_ESCAPE || event.type == SDL_EVENT_QUIT) {

                running = false;
            }

            // Gathers the new height and width of the window after being resized
            if (event.type == SDL_EVENT_WINDOW_RESIZED) {
                
                current_width = event.window.data1;
                current_height= event.window.data2;

                SDL_Log("Window size changed: %d x %d", current_width, current_height);

                // Reposition paddles to account for new screen size
                paddleOne.Resize(current_width, current_height);
                paddleTwo.Resize(current_width, current_height);

                SDL_Log("Paddle 1 height is %d", paddleOne.height);
                SDL_Log("Paddle 2 height is %d", paddleTwo.height);
            }
        }

        // Clear the window background to black
        // R,G,B
        SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(renderer);
        
        // Draw the net
        DrawNet(renderer, current_width, current_height);

        // Update the ball's position
        ball.Update(current_width, current_height);

        // Update paddle positions
        paddleOne.Update(current_height);
        paddleTwo.Update(current_height);

        // Draw the ball
        ball.Draw(renderer);

        // Collision detection between paddles and ball
        if (SDL_HasRectIntersectionFloat(&ball.rect, &paddleOne.rect)) {

            if (ball.velocity.x < 0) {
                
                ball.velocity.x *= -1;

                // Find the centers of the paddle and ball
                float paddleCenterY = paddleOne.rect.y + (paddleOne.rect.h / 2);
                float ballCenterY = ball.rect.y + (ball.rect.h / 2);

                // Find the relative position
                // -1 means the ball hit the top
                // 1 means the ball hit the bottom
                float relativePositionY = (ballCenterY - paddleCenterY) / (paddleOne.rect.h / 2);

                // Set the new y velocity based on the factor calculated above
                // Multiple by max bounce angle constant
                ball.velocity.y = relativePositionY * Ball::MAX_BOUNCE_ANGLE;
            }
        }
        else if (SDL_HasRectIntersectionFloat(&ball.rect, &paddleTwo.rect)) {

            if (ball.velocity.x > 0) {
                
                ball.velocity.x *= -1;

                // Find the centers of the paddle and ball
                float paddleCenterY = paddleTwo.rect.y + (paddleTwo.rect.h / 2);
                float ballCenterY = ball.rect.y + (ball.rect.h / 2);

                // Find the relative position
                // -1 means the ball hit the top
                // 1 means the ball hit the bottom
                float relativePositionY = (ballCenterY - paddleCenterY) / (paddleTwo.rect.h / 2);

                // Set the new y velocity based on the factor calculated above
                // Multiple by max bounce angle constant
                ball.velocity.y = relativePositionY * Ball::MAX_BOUNCE_ANGLE;
            }
        }

        // Draw the paddles
        paddleOne.Draw(renderer);
        paddleTwo.Draw(renderer);

        // Presents the backbuffer to show final drawn image at the end of a frame
        // Prevents player from seeing things being drawn in real time
        SDL_RenderPresent(renderer);
    }
    
    // Cleanup SDL 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}