#include "MatrixBase.h"

namespace meltrix {

    /// \brief Default Constructor
    /// \param rows The number of rows in the matrix
    /// \param cols The number of columns in the matrix
    Matrix::Matrix(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols);
    };

    /// \brief Default Constructor
    /// \param rows The number of rows in the matrix
    /// \param cols The number of columns in the matrix
    /// \param value The value to populate the matrix with
    Matrix::Matrix(int rows, int cols, const double& value) {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols, value);
    }

    /// \brief Default Constructor
    /// \param rows The number of rows in the matrix
    /// \param cols The number of columns in the matrix
    /// \param data The data to populate the matrix with
    Matrix::Matrix(int rows, int cols, const std::vector<double>& data) {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        if (data.size() != rows * cols) {
            throw std::invalid_argument("Data size must match matrix dimensions");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data = data;
    }


    /// \brief Copy constructor
    /// \param other The matrix to copy
    Matrix::Matrix(const Matrix& other) {
        m_Rows = other.m_Rows;
        m_Cols = other.m_Cols;
        m_Data = other.m_Data;
    };

    // ============================= //
    // ===== SCALAR OPERATIONS ===== //
    // ============================= //

    /// \brief Scalar addition
    /// \param scalar The scalar to add
    /// \return The resulting matrix
    Matrix Matrix::operator+(const double &scalar) const {
        Matrix result = *this;
        for (double x : result.m_Data) {
            x += scalar;
        }
        return result;
    }

    /// \brief Scalar subtraction
    /// \param scalar The scalar to subtract
    /// \return The resulting matrix
    Matrix Matrix::operator-(const double &scalar) const {
        Matrix result = *this;
        for (double x : result.m_Data) {
            x -= scalar;
        }
        return result;
    }

    /// \brief Scalar multiplication
    /// \param scalar The scalar to multiply
    /// \return The resulting matrix
    Matrix Matrix::operator*(const double &scalar) const {
        Matrix result = *this;
        for (double x : result.m_Data) {
            x *= scalar;
        }
        return result;
    }

    /// \brief Inline scalar addition
    /// \param scalar The scalar to add
    void Matrix::operator+=(const double &scalar) {
        for (double x : m_Data) {
            x += scalar;
        }
    }

    /// \brief Inline scalar subtraction
    /// \param scalar The scalar to subtract
    void Matrix::operator-=(const double &scalar) {
        for (double x : m_Data) {
            x -= scalar;
        }
    }

    /// \brief Inline scalar multiplication
    /// \param scalar The scalar to multiply
    void Matrix::operator*=(const double &scalar) {
        for (double x : m_Data) {
            x *= scalar;
        }
    }

    // ============================= //
    // ===== MATRIX OPERATIONS ===== //
    // ============================= //

    /// \brief Matrix addition
    /// \param other The matrix to add
    /// \return The resulting matrix
    Matrix Matrix::operator+(const Matrix &other) const {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result = *this;
        for (int i = 0; i < m_Data.size(); i++) {
            result.m_Data[i] += other.m_Data[i];
        }
        return result;
    }

    /// \brief Matrix subtraction
    /// \param other The matrix to subtract
    /// \return The resulting matrix
    Matrix Matrix::operator-(const Matrix &other) const {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result = *this;
        for (int i = 0; i < m_Data.size(); i++) {
            result.m_Data[i] -= other.m_Data[i];
        }
        return result;
    }

    /// \brief Inline matrix addition
    /// \param other The matrix to add
    void Matrix::operator+=(const Matrix &other) {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        for (int i = 0; i < m_Data.size(); i++) {
            m_Data[i] += other.m_Data[i];
        }
    }

    /// \brief Inline matrix subtraction
    /// \param other The matrix to subtract
    void Matrix::operator-=(const Matrix &other) {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        for (int i = 0; i < m_Data.size(); i++) {
            m_Data[i] -= other.m_Data[i];
        }
    }

    // ============================= //
    // ===== ACCESSOR METHODS ====== //
    // ============================= //

    /// \brief Accessor operator
    /// \param row The row to access
    /// \param col The column to access
    /// \return The value at the specified row and column
    double& Matrix::operator()(int row, int col) {
        if (row < 0 || row >= m_Rows || col < 0 || col >= m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        return m_Data[row * m_Cols + col];
    }

    /// \brief Get a row of the matrix
    /// \param row The row to get
    /// \return The row as a matrix
    Matrix Matrix::getRow(int row) {
        if (row < 0 || row >= m_Rows) {
            throw std::invalid_argument("Index out of bounds");
        }
        Matrix result(1, m_Cols);
        for (int i = 0; i < m_Cols; i++) {
            result(0, i) = m_Data[row * m_Cols + i];
        }
        return result;
    }

    /// \brief Get a column of the matrix
    /// \param col The column to get
    /// \return The column as a matrix
    Matrix Matrix::getCol(int col) {
        if (col < 0 || col >= m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        Matrix result(m_Rows, 1);
        for (int i = 0; i < m_Rows; i++) {
            result(i, 0) = m_Data[i * m_Cols + col];
        }
        return result;
    }

    /// \brief Get a submatrix from the matrix
    /// \param rowStart The starting row
    /// \param rowEnd The ending row
    /// \param colStart The starting column
    /// \param colEnd The ending column
    /// \return The submatrix
//    Matrix Matrix::getSubMatrix(int rowStart, int rowEnd, int colStart, int colEnd) {
//        if (rowStart < 0 || rowStart >= m_Rows || rowEnd < 0 || rowEnd >= m_Rows || colStart < 0 || colStart >= m_Cols || colEnd < 0 || colEnd >= m_Cols) {
//            throw std::invalid_argument("Index out of bounds");
//        }
//        if (rowStart > rowEnd || colStart > colEnd) {
//            throw std::invalid_argument("Start index must be less than end index");
//        }
//        Matrix result(rowEnd - rowStart + 1, colEnd - colStart + 1);
//        for (int i = rowStart; i <= rowEnd; i++) {
//            for (int j = colStart; j <= colEnd; j++) {
//                result(i - rowStart, j - colStart) = m_Data[i * m_Cols + j];
//            }
//        }
//        return result;
//    }
    Matrix Matrix::getSubMatrix(int row, int col) {
        if (row < 0 || row > m_Rows || col < 0 || col > m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        if (m_Rows == 1 || m_Cols == 1) {
            throw std::invalid_argument("Cannot get sub-matrix from current matrix");
        }

        std::vector<double> newData = {};
        for (int i = 0; i < m_Rows; i++) {
            for (int j = 0; j < m_Cols; j++) {
                if (i == row || j == col) {
                    continue;
                } else {
                    newData.push_back(m_Data[i * m_Cols + j]);
                }
            }
        }

    }

    // ============================= //
    // ===== MATRIX FUNCTIONS ====== //
    // ============================= //

    /// \brief Matrix multiplication
    /// \param other The matrix to multiply
    /// \return The resulting matrix
    Matrix Matrix::dot(Matrix& other) {
        if (m_Cols != other.m_Rows) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result(m_Rows, other.m_Cols);
        for (int i = 0; i < m_Rows; i++) {
            for (int j = 0; j < other.m_Cols; j++) {
                double sum = 0;
                for (int k = 0; k < m_Cols; k++) {
                    sum += m_Data[i * m_Cols + k] * other.m_Data[k * other.m_Cols + j];
                }
                result(i, j) = sum;
            }
        }
        return result;
    }

    /// \brief Apply a function to each individual item of the matrix
    /// \param func The function to be executed
    void Matrix::applyFunction(const std::function<double(double)>& func) {
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), func);
    }

    /// \brief Transposes the matrix
    void Matrix::transpose() {
        std::vector<double> newData = {};
        for (int col = 0; col < m_Cols; col++) {
            for (int row = 0; row < m_Rows; row++) {
                newData.push_back(m_Data[row * m_Cols + col]);
            }
        }
        std::swap(m_Rows, m_Cols);
        m_Data = newData;
    }

    // ============================= //
    // ===== UTILITY FUNCTIONS ===== //
    // ============================= //

    /// \brief Prints the matrix, aligning the elements
    void Matrix::print() const {
        int maxLen = 0;
        for (double x : m_Data) {
            std::string str = std::to_string(x);
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
            int len = str.length();
            maxLen = std::max(maxLen, len);
        }
        std::cout << "┌ " << std::setw(maxLen * m_Cols + m_Cols - 1) << " " << " ┐\n";
        for (int i = 0; i < m_Rows; i++) {
            std::cout << "│ ";
            for (int j = 0; j < m_Cols; j++) {
                std::cout << std::setw(maxLen) << m_Data[i * m_Cols + j] << " ";
            }
            std::cout << "│\n";
        }
        std::cout << "└ " << std::setw(maxLen * m_Cols + m_Cols - 1) << " " << " ┘\n";
    }

    /// \brief Returns the shape of the matrix
    std::pair<int, int> Matrix::shape() {
        return std::pair(m_Rows, m_Cols);
    }

} // meltrix