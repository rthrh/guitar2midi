#ifndef SDL_UTILS_H
#define SDL_UTILS_H
#include "SDL2/SDL.h"
#include <iostream>
class sdlPlayer
{
public:
    sdlPlayer(std::string path);




//private:
    //Uint8* sampData;
    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;
    SDL_AudioDeviceID aDevice;

};

#endif // SDL_UTILS_H
