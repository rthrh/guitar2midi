#ifndef FFTRUNNER_H
#define FFTRUNNER_H

#include <iostream>
#include <fftw3.h>


class fftRunner
{
public:
    fftRunner(uint8_t channels, uint16_t length);
    ~fftRunner();
    void feedData(uint8_t *stream);
    void execute();
    void printChannel(uint8_t channelNum);

    fftw_complex *in[2];
    fftw_complex *out[2];
    fftw_plan p[2];
    uint16_t length;
    uint8_t channels;
};

#endif // FFTRUNNER_H
