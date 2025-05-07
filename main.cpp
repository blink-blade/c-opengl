#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <cstddef>
#include <iostream>
#include "helpers.h"

using namespace std;


SDL_Rect dest;
// SDL_Rect rects[1000000];

int main(int argc, char *argv[])
{
 
    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    
    char p[8] = "map.png";
    struct rectWTex rect = getRectFromPath(p, 0, 0, 10, 10);
    // }
    // SDL_BlitSurface();
    int offsetX = -10;
    int offsetY = 0;
    int speed = 37;

    // animation loop
    while (running) {
        double now = SDL_GetTicks();
        handleControls();
        if (keys[SDL_SCANCODE_A]) {
            offsetX += speed;
        }
        if (keys[SDL_SCANCODE_D]) {
            offsetX -= speed;
        }
        if (keys[SDL_SCANCODE_S]) {
            offsetY -= speed;
        }
        if (keys[SDL_SCANCODE_W]) {
            offsetY += speed;
        }
        
        int i = 100;
        // clears the screen
        SDL_RenderClear(renderer);
        for (int x = 0; x < 750; x++) {
            rect.SDLRect.x = x * 10 + offsetX;
            rect.SDLRect.y = offsetY;
            for (int y = 0; y < 100; y++) {
                SDL_RenderCopy(renderer, rect.texture, NULL, &rect.SDLRect);
                rect.SDLRect.y += 10;
            }
            if (i == 100) {
                i = 0;
                SDL_RenderCopy(renderer, rect.texture, NULL, &rect.SDLRect);
            }
            else {
                i += 1;
            }

        }

        
        double end = SDL_GetTicks();
        cout<<(end - now) / 1000<<"\n";
        // triggers the double buffers
        // for multiple rendering
        SDL_RenderPresent(renderer);
 
        // calculates to 60 fps
        SDL_Delay(1000 / 60);
    }
 
    // destroy texture
    SDL_DestroyTexture(rect.texture);
 
    // destroy renderer
    SDL_DestroyRenderer(renderer);
 
    // destroy window
    SDL_DestroyWindow(window);
     
    // close SDL
    SDL_Quit();
 
    return 0;
}