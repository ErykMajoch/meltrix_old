#include "ZeroMatrix.h"

namespace meltrix {

    ZeroMatrix::ZeroMatrix(int size) {
        m_Rows = size;
        m_Cols = size;
        m_Data.resize(size * size, 0);
    };

} // meltrix