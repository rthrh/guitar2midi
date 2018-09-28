#include "fftrunner.h"


fftRunner::fftRunner(uint8_t channelsNum, uint16_t l)
{
    this->channels = channelsNum;
    this->length = l;


    //malloc space for fftw arrays
    for(int i=0; i<channels; ++i){
        in[i] = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * length);
        out[i] = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * length);
    }

    //create a plan
    for(int c = 0; c < channels; ++c){
        p[c] = fftw_plan_dft_1d(length, in[c],
                out[c], FFTW_FORWARD, FFTW_MEASURE);
    }

}

fftRunner::~fftRunner()
{
 //free menory...
}

void fftRunner::feedData(uint8_t *stream)
{
    //feed DFT input data array
    for(int i=0; i<channels; i++)
    {
        for (int j=0; j < length; j++)
        {
            in[i][j][0] = stream[j];
        }
    }
}

void fftRunner::execute()
{
    //execute DFT
    for(int c = 0; c < channels; ++c){
        fftw_execute(p[c]);
    }


}

void fftRunner::printChannel(uint8_t channelNum)
{
    //print 1st channel
    double FFTmax = 0;
    uint FFTmaxIndex = 0;
    for(int c = 0; c < length; c++){
        //std::cout << out[0][c][0] << std::endl;
        if ((out[0][c][0] > FFTmax) && (c > 0))
        {
            FFTmax = out[0][c][0];
            FFTmaxIndex = c;
        }
    }
    std::cout << "FFTmax: " << FFTmax << " FFTmaxIndex: " << FFTmaxIndex << std::endl;
}
