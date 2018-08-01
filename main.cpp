#include <iostream>
#include <assert.h>

#include "SDL2/SDL.h"
#include "utils.hpp"
#include <fftw3.h>



Uint8* sampData;
SDL_AudioSpec wavSpec;
Uint8* wavStart;
Uint32 wavLength;
SDL_AudioDeviceID aDevice;

uint globalCounter = 0;

struct AudioData {
    Uint8* filePosition;
    Uint32 fileLength;
};

void PlayAudioCallback(void* userData, Uint8* stream, int streamLength);

int main() {
    SDL_Init(SDL_INIT_AUDIO);


    // Load .wav file
    if (SDL_LoadWAV("/home/adpa/guitar2midi/res/sample_1.wav", &wavSpec, &wavStart, &wavLength) == NULL) {
        std::cerr << "Couldnt load file: "  << std::endl;
        getchar();
    }
    std::cout << "Loaded file" << std::endl;

    AudioData audio;
    audio.filePosition = wavStart;
    audio.fileLength = wavLength;

    wavSpec.callback = PlayAudioCallback;
    wavSpec.userdata = &audio;

    utils::printWavSpec(wavSpec);

    // Open audio playback endpoint
    aDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (aDevice == 0) {
        std::cerr << "Audio Device connection failed: " << SDL_GetError() << std::endl;
        getchar();
    }
    // Play audio on playback endpoint
    SDL_PauseAudioDevice(aDevice, 0);

    // Do nothing while there's still data to be played
    while (audio.fileLength > 0) {
        SDL_Delay(100);
    }
}



void PlayAudioCallback(void* userData, Uint8* stream, int streamLength) {
    AudioData* audio = (AudioData*)userData;
    sampData = new Uint8;

    if (audio->fileLength == 0) {
        return;
    }
    //std::cout << "GlobalCounter: " << ++globalCounter << std::endl;
    std::cout << "AudioData.streamLength: " << streamLength << std::endl;
    std::cout << "AudioData.fileLength: " << audio->fileLength << std::endl;
    Uint32 length = (Uint32)streamLength;
    length = (length > audio->fileLength ? audio->fileLength : length);

    SDL_memcpy(stream, audio->filePosition, length);

    // HERE is where i'd like to implement the FFT on 'stream' data
    // but i don't know how to implement this using FFTW
//fileLength 1535696/ streamLength16384

    int channels = 2; //to automatize
    fftw_complex *in[channels], *out[channels];
    fftw_plan p[channels];
    int N = streamLength; //apply nyquist/hermitian?


    for(int i=0; i<channels; ++i){
        in[i] = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
        out[i] = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
        //vis_pkg->fftw_ptr[i].index = i;
    }

    for(int c = 0; c < channels; ++c){
        p[c] = fftw_plan_dft_1d(streamLength, in[c],
                out[c], FFTW_FORWARD, FFTW_MEASURE);
    }



    audio->filePosition += length;
    audio->fileLength -= length;
}
