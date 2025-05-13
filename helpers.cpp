#include <cstddef>
#include <cstdlib>
#include <string>
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

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}