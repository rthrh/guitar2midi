#include "sdl_utils.h"

sdlPlayer::sdlPlayer(std::string path)
{
    SDL_Init(SDL_INIT_AUDIO);

    // Load .wav file
    if (SDL_LoadWAV(path.c_str(), &wavSpec, &wavStart, &wavLength) == NULL) {
        std::cerr << "Couldnt load file: "  << std::endl;
        throw;
    }
}



