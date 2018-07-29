#include <iostream>
#include <assert.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    SDL_LoadWAV("/home/adpa/guitar2midi/sample_1.wav", &wavSpec, &wavBuffer, &wavLength);


    // open audio device

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

    // play audio

    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);



    SDL_Delay(3000);


    SDL_CloseAudioDevice(deviceId);
    //SDL_FreeWAV(wavBuffer);
    //SDL_Quit();
    std::cout << "PROGRAM FINISHED" << std::endl;

    return 1;
}
