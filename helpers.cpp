#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <string>
#include "stdint.h"
#include "inttypes.h"

using namespace std;

const uint8_t* keys = SDL_GetKeyboardState(NULL);
bool running = true;

SDL_Window* window = SDL_CreateWindow("GAME", // creates a window
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    1000, 1000, 0);
// triggers the program that controls
// your graphics hardware and sets flags
Uint32 render_flags = SDL_RENDERER_ACCELERATED;
// creates a renderer to render our images
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, render_flags);

void handleControls() {
    SDL_PumpEvents();

    SDL_Event event;
    
    // Events management
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            // handling of close button
            running = false;
            break;
        }
    }
}

struct rectWTex {
    SDL_Rect SDLRect;
    SDL_Texture* texture;
};

rectWTex getRectFromPath(char *path, int x, int y, int w, int h) {
    struct rectWTex rect;

    // creates a surface to load an image into the main memory
    SDL_Surface* surface;

    surface = IMG_Load(path);
    
    // loads image to our graphics hardware memory.
    rect.texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    // clears main-memory
    SDL_FreeSurface(surface);

    // connects our texture with dest to control position
    SDL_QueryTexture(rect.texture, NULL, NULL, &rect.SDLRect.w, &rect.SDLRect.h);

    rect.SDLRect.x = x;
    rect.SDLRect.y = y;
    rect.SDLRect.w = w;
    rect.SDLRect.h = h;

    return rect;
}
