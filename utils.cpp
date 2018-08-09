
#include "utils.hpp"
#include <iostream>
#include <fftw3.h>
#include "maths.hpp"

namespace utils{


    int test(void){

        int N = 10; //apply nyquist/hermitian?
        int streamLength = N;

        //double stream[] = {1,1,1,1,1,1,1,1,1,1};

        std::vector<double> linspace = maths::linspace(0, M_PI, 10);
        maths::print_vector(linspace);

        std::vector<double> stream = maths::sinwave(linspace);
        maths::print_vector(stream);

        int channels = 1;
        fftw_complex *in[channels], *out[channels];
        fftw_plan p[channels];

        for(int i=0; i<channels; ++i){
            in[i] = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
            out[i] = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
        }

        for(int i=0; i<N; ++i){
            in[0][i][0] = stream[i];
            std::cout << "DFTIN:" << in[0][i][0] << "   STREAMIN:" << stream[i] << std::endl;
        }

        //create plan for DFT execution
        for(int c = 0; c < channels; ++c){
            p[c] = fftw_plan_dft_1d(streamLength, in[c],
                    out[c], FFTW_FORWARD, FFTW_MEASURE);
        }

        //execute DFT
        for(int c = 0; c < channels; ++c){
            fftw_execute(p[c]);
            //std::cout << "exec" << std::endl;
        }

        //print 1st channel
        for(int c = 0; c < N; ++c){
            std::cout << out[0][c][0] << " || " << out[0][c][1] << std::endl;
        }


        return 1;
    }


}
