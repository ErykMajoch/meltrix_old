#include "ZeroMatrix.h"

namespace meltrix {

        /// \brief Initializes a new instance of the <see cref="ZeroMatrix"/> class.
        /// \param size The size of the matrix

        ZeroMatrix::ZeroMatrix(int size) {
            m_Rows = size;
            m_Cols = size;
            m_Data.resize(size * size, 0);
        };

} // meltrix