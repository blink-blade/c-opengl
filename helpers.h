#include <cstddef>
#include <string>
#include "stdint.h"
#include "inttypes.h"
#include "stdint.h"
#include "glad.h" 
#include "khrplatform.h"
#include <GLFW/glfw3.h>
#include "inttypes.h"
#include <fstream>
#include <iostream>

#ifndef HELPERS
#define HELPERS

using namespace std;
// struct rectWTex {
//     SDL_Rect SDLRect;
//     SDL_Texture* texture;
// };
extern int scroll;
// extern bool running;
// extern const uint8_t* keys;
// extern SDL_Window* window;
// extern SDL_Renderer *renderer;
// void handleControls();
// rectWTex getRectFromPath(char *path, int x, int y, int w, int h);
extern void processInput(GLFWwindow *window);
extern void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
extern const char* readFile(string path);
extern float cameraAttrs[4];

#endif