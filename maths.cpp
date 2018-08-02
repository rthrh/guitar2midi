#include "maths.hpp"
#include <math.h>

namespace maths{





    std::vector<double> sinwave(std::vector<double> linspace)
    {
        std::vector<double> sinwaved(linspace.size());
        for (int i = 0; i < linspace.size(); i++)
        {
            sinwaved[i] = sin(linspace[i]);
        }

        return sinwaved;

    }

    //to improve
    std::vector<double> linspace(double start, double end, uint num)
    {

      std::vector<double> linspaced;

      if (num == 0) { return linspaced; }
      if (num == 1)
        {
          linspaced.push_back(start);
          return linspaced;
        }

      double delta = (end - start) / (num - 1);

      for(int i=0; i < num-1; ++i)
        {
          linspaced.push_back(start + delta * i);
        }
      linspaced.push_back(end); // I want to ensure that start and end
                                // are exactly the same as the input
      return linspaced;
    }

    void print_vector(std::vector<double> vec)
    {
      std::cout << "size: " << vec.size() << std::endl;
      for (double d : vec)
        std::cout << d << " ";
      std::cout << std::endl;
    }

    void print_vector_of_vectors(std::vector<std::vector<double> > vec)
    {
        std::cout << "lets start" << std::endl;
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                std::cout << "hi there" << std::endl;
                std::cout << vec[i][j];
            }
        }
    }
}
