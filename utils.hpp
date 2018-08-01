#ifndef UTILS_HPP
#define UTILS_HPP
#include "SDL2/SDL.h"

namespace utils{
    void closeAudio(Uint8 *wavBuffer, SDL_AudioDeviceID deviceId);
    void printWavSpec(SDL_AudioSpec wavSpec);


}
#endif // UTILS_HPP

