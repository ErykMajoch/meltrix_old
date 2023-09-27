#pragma once

#include "MatrixBase.h"

namespace meltrix {

    enum DISTRIBUTION_TYPE {
        UNIFORM,
        BINOMIAL,
        NORMAL,
    };

    class RandomMatrix : public Matrix {
    public:
        RandomMatrix(int rows, int cols, DISTRIBUTION_TYPE type);
        RandomMatrix(int rows, int cols, DISTRIBUTION_TYPE type, double param1, double param2);
    };

}