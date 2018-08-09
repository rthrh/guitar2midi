#ifndef SDL_UTILS_H
#define SDL_UTILS_H
#include "SDL2/SDL.h"
#include <iostream>
#include <fftw3.h>
#include "fftrunner.h"

class sdlPlayer
{
public:
    sdlPlayer(std::string path);
    void playSound();
    static void PlayAudioCallback(void* userData, Uint8* stream, int streamLength);
    void pause(Uint16 s);

//private:
    //Uint8* sampData;
    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;
    SDL_AudioDeviceID aDevice;

    struct AudioData {
        Uint8* filePosition;
        Uint32 fileLength;
    };

    AudioData audio;
};

#endif // SDL_UTILS_H
