#include "IdentityMatrix.h"

namespace meltrix {

    IdentityMatrix::IdentityMatrix(int size) {
        m_Rows = size;
        m_Cols = size;
        m_Data.resize(size * size, 0);
        for (int i = 0; i < size; i++) {
            m_Data[i * size + i] = 1;
        }
    };

} // meltrix