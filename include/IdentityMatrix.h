#pragma once

#include "MatrixBase.h"

namespace meltrix {

    /// <summary>
    /// A matrix builder class which makes an identity matrix
    /// </summary>
    class IdentityMatrix : public Matrix {
    public:
        IdentityMatrix(int size);
    };

} // meltrix