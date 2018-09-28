#include <iostream>
#include <assert.h>

#include "SDL2/SDL.h"
#include "utils.hpp"
#include "test.cpp"
#include "maths.hpp"
#include <fftw3.h>
#include "sdl_utils.h"





uint globalCounter = 0;



int main() {
    //SDL example wav play
    sdlPlayer sdl("/home/adpa/guitar2midi/res/sample_1.wav");
    sdl.playSound();
    sdl.pause(100);

}



