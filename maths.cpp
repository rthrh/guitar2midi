#include "maths.hpp"
#include <math.h>

namespace maths{





    std::vector<double> sinwave(std::vector<double> linspace)
    {
        std::vector<double> sinwaved(linspace.size());
        std::cout << "nside sinwave" << std::endl;
        for (int i = 0; i < linspace.size(); i++)
        {
            std::cout << "nside loop:" << sin(linspace[i]) << std::endl;
            sinwaved[i] = sin(linspace[i]);

        }

        std::cout << "at the end of sinwave" << std::endl;

        return sinwaved;

    }


    std::vector<double> linspace(double start_in, double end_in, uint num_in)
    {

      std::vector<double> linspaced;

      double start = static_cast<double>(start_in);
      double end = static_cast<double>(end_in);
      uint num = static_cast<double>(num_in);

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
