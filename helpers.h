#include "stdint.h"
#include "inttypes.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>

#ifndef HELPERS
#define HELPERS

struct rectWTex {
    SDL_Rect SDLRect;
    SDL_Texture* texture;
};

extern bool running;
extern const uint8_t* keys;
extern SDL_Window* window;
extern SDL_Renderer *renderer;
void handleControls();
rectWTex getRectFromPath(char *path, int x, int y, int w, int h);

#endif