#include "sdl_utils.h"

sdlPlayer::sdlPlayer(std::string path)
{
    SDL_Init(SDL_INIT_AUDIO);

    // Load .wav file
    if (SDL_LoadWAV(path.c_str(), &wavSpec, &wavStart, &wavLength) == NULL) {
        std::cerr << "Couldnt load file: "  << std::endl;
        throw;
    }

    audio.filePosition = wavStart;
    audio.fileLength = wavLength;

    wavSpec.callback = PlayAudioCallback;
    wavSpec.userdata = &audio;


    // Open audio playback endpoint
    aDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (aDevice == 0) {
        std::cerr << "Audio Device connection failed: " << SDL_GetError() << std::endl;
        throw;
    }


}


void sdlPlayer::playSound()
{
    SDL_PauseAudioDevice(aDevice, 0);
}

void sdlPlayer::pause(Uint16 time)
{
    // Do nothing while there's still data to be played
    while (audio.fileLength > 0) {
        SDL_Delay(100);
    }
}

void sdlPlayer::PlayAudioCallback(void* userData, Uint8* stream, int streamLength) {
    AudioData* audio = (AudioData*)userData;
    Uint8* sampData = new Uint8;


    if (audio->fileLength == 0) {
        return;
    }

    Uint32 length = (Uint32)streamLength;
    length = (length > audio->fileLength ? audio->fileLength : length);
    SDL_memcpy(stream, audio->filePosition, length);


    //FFTW part
    int channels = 2; //to automatize
    fftRunner fft(channels, length);
    fft.feedData(stream);
    fft.execute();
    fft.printChannel(0);

    audio->filePosition += length;
    audio->fileLength -= length;
}
