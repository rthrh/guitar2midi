#include <iostream>
#include <assert.h>

#include "SDL2/SDL.h"
#include "utils.hpp"
#include <fftw3.h>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    SDL_LoadWAV("/home/adpa/guitar2midi/res/sample_1.wav", &wavSpec, &wavBuffer, &wavLength);

    assert(0 != wavSpec.samples);

    std::cout << "freq: " << wavSpec.freq << std::endl;
    std::cout << "channels: " << static_cast<Uint8>(wavSpec.channels) << std::endl;
    std::cout << "silence: " << wavSpec.silence << std::endl;
    std::cout << "samples: " << wavSpec.samples << std::endl;
    std::cout << "padding: " << wavSpec.padding << std::endl;
    std::cout << "size: " << wavSpec.size << std::endl;

    //int channels = GetSDL_AudioSpec(wavSpec)->channels;

    //FFTW3 part
    int N = wavSpec.samples;
    assert (N > 0);




    //END




    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

    // play audio
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);

    SDL_Delay(3000);



    utils::closeAudio(wavBuffer, deviceId);

    std::cout << "PROGRAM FINISHED" << std::endl;

    return 1;
}
