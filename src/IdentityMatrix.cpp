#include "IdentityMatrix.h"

namespace meltrix {

    /// \brief Initializes a new instance of the <see cref="IdentityMatrix"/> class.
    /// \param size The size of the matrix

    IdentityMatrix::IdentityMatrix(int size) {
        m_Rows = size;
        m_Cols = size;
        m_Data.resize(size * size, 0);
        for (int i = 0; i < size; i++) {
            m_Data[i * size + i] = 1;
        }
    };

} // meltrix