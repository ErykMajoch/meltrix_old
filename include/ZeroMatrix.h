#pragma once

#include "MatrixBase.h"

namespace meltrix {

    /// <summary>
    /// A matrix builder class which makes a matrix of zeros
    /// </summary>
    class ZeroMatrix : public Matrix {
    public:
        ZeroMatrix(int size);
    };

} // meltrix