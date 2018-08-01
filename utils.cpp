#include "SDL2/SDL.h"
#include "utils.hpp"
#include <iostream>

namespace utils{
    void closeAudio(Uint8 *wavBuffer, SDL_AudioDeviceID deviceId)
    {


    }

    void printWavSpec(SDL_AudioSpec wavSpec)
    {
        printf("Frequency %d\n", wavSpec.freq);
        printf("Channels %d\n", wavSpec.channels);
        printf("Silence %d\n", wavSpec.silence);
        printf("Samples: %d\n", wavSpec.samples);
        printf("Padding %d\n", wavSpec.padding);
        printf("Size %d\n", wavSpec.size);
    }


}
