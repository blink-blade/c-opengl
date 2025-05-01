#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

using namespace std;

class Mammal {
public:
    int legs = 4;
    bool mouth = true;
};

class Dog : Mammal {
public:
    void func () {

        // Accessing Base class members
        cout << legs;
        cout << "\n";
        legs = 22;
        cout << legs;
    }
};

int main() {
    class Dog Jeff;
    Jeff.func();
}