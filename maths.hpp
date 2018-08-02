#ifndef MATHS_HPP
#define MATHS_HPP

#include <iostream>
#include <vector>

namespace maths{
    std::vector<double> sinwave(std::vector<double> linspace);
    std::vector<double> linspace(double start_in, double end_in, uint num_in);
    void print_vector(std::vector<double> vec);
    void print_vector_of_vectors(std::vector<std::vector<double> > vec);
}



#endif // MATHS_HPP

