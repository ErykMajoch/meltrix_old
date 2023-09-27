#pragma once

#include "MatrixBase.h"

namespace meltrix {

    /// <summary>
    /// The distribution types of random matrices
    /// </summary>
    enum DISTRIBUTION_TYPE {
        UNIFORM,
        BINOMIAL,
        NORMAL,
    };

    /// <summary>
    /// A matrix builder which create a matrix with random values
    /// </summary>
    class RandomMatrix : public Matrix {
    public:
        RandomMatrix(int rows, int cols, DISTRIBUTION_TYPE type);
        RandomMatrix(int rows, int cols, DISTRIBUTION_TYPE type, double param1, double param2);
    };

}