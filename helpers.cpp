#include <cstddef>
#include <cstdlib>
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "stdint.h"
#include "inttypes.h"
#include "stdint.h"
#include "glad.h" 
#include "khrplatform.h"
#include <GLFW/glfw3.h>
#include "inttypes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// x, y, z, fov,
float cameraAttrs[4] = {0.0f, 0.0f, -3.0f, 45.0f};
// -1 = down, 0 = none, 1 = up.
int scroll = 0;

const char* readFile(string path) {
    ostringstream sstream;
    std::ifstream fs(path);
    sstream << fs.rdbuf();
    const std::string str(sstream.str());
    const char* ptr = str.c_str();
    // ptr is the pointer we wanted - do note that it's only valid
    // while str is valid (i.e. not after str goes out of scope)
    cout << ptr;
    return ptr;
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    // Handle scroll input here
    // xoffset: Horizontal scroll offset (positive for right, negative for left)
    // yoffset: Vertical scroll offset (positive for up, negative for down)
    if (yoffset > 0) {
        // Scrolled up
        scroll = 1;
    } else if (yoffset < 0) {
        // Scrolled down
        scroll = -1;
    }
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cameraAttrs[0] -= 0.1;
    }
    // Movement:
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cameraAttrs[0] += 0.1;
    }
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        cameraAttrs[1] -= 0.1;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        cameraAttrs[1] += 0.1;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cameraAttrs[2] -= 0.1;
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cameraAttrs[2] += 0.1;
    }   

    if(scroll == 1) {
        cameraAttrs[3] -= 2;
    }

    if(scroll == -1) {
        cameraAttrs[3] += 2;
    }
    // cout << cameraAttrs[3] << "\n";

}