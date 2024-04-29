#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#include "snake.c"
 
int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    
  
    int running = 1;

    while (running == 1) {
        // clears the screen
        SDL_RenderClear(rend);
        SDL_Event event;
 
        // Events management
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
 
            case SDL_QUIT:
                // handling of close button
                running = 0;
                break;
 
            }
        }

        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = 200;
        rect.h = 200;

        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_RenderDrawRect(rend, &rect);
        SDL_RenderFillRect(rend, &rect);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);


        SDL_RenderPresent(rend);
        
        
 
        // calculates to 60 fps
        SDL_Delay(1000 / 60);
    }
 

 
    // destroy renderer
    SDL_DestroyRenderer(rend);
 
    // destroy window
    SDL_DestroyWindow(win);
     
    // close SDL
    SDL_Quit();
 
    return 0;
}