#include "MatrixBase.h"

namespace meltrix {

    Matrix::Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols);
    };

    Matrix::Matrix(int rows, int cols, const double& value)
    {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols, value);
    }

    Matrix::Matrix(int rows, int cols, const std::vector<double>& data)
    {
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

    Matrix::Matrix(const Matrix& other)
    {
        m_Rows = other.m_Rows;
        m_Cols = other.m_Cols;
        m_Data = other.m_Data;
    };

    // ============================= //
    // ===== SCALAR OPERATIONS ===== //
    // ============================= //

    Matrix Matrix::operator+(const double &scalar) const
    {
        Matrix result = *this;
        for (double x : result.m_Data) {
            x += scalar;
        }
        return result;
    }

    Matrix Matrix::operator-(const double &scalar) const
    {
        Matrix result = *this;
        for (double x : result.m_Data) {
            x -= scalar;
        }
        return result;
    }

    Matrix Matrix::operator*(const double &scalar) const
    {
        Matrix result = *this;
        for (double x : result.m_Data) {
            x *= scalar;
        }
        return result;
    }

    void Matrix::operator+=(const double &scalar)
    {
        for (double x : m_Data) {
            x += scalar;
        }
    }

    void Matrix::operator-=(const double &scalar)
    {
        for (double x : m_Data) {
            x -= scalar;
        }
    }

    void Matrix::operator*=(const double &scalar)
    {
        for (double x : m_Data) {
            x *= scalar;
        }
    }

    // ============================= //
    // ===== MATRIX OPERATIONS ===== //
    // ============================= //

    Matrix Matrix::operator+(const Matrix &other) const
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result = *this;
        for (int i = 0; i < m_Data.size(); i++) {
            result.m_Data[i] += other.m_Data[i];
        }
        return result;
    }

    Matrix Matrix::operator-(const Matrix &other) const
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result = *this;
        for (int i = 0; i < m_Data.size(); i++) {
            result.m_Data[i] -= other.m_Data[i];
        }
        return result;
    }

    void Matrix::operator+=(const Matrix &other)
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        for (int i = 0; i < m_Data.size(); i++) {
            m_Data[i] += other.m_Data[i];
        }
    }

    void Matrix::operator-=(const Matrix &other)
    {
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

    double& Matrix::operator()(int row, int col)
    {
        if (row < 0 || row >= m_Rows || col < 0 || col >= m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        return m_Data[row * m_Cols + col];
    }

    Matrix Matrix::getRow(int row)
    {
        if (row < 0 || row >= m_Rows) {
            throw std::invalid_argument("Index out of bounds");
        }
        Matrix result(1, m_Cols);
        for (int i = 0; i < m_Cols; i++) {
            result(0, i) = m_Data[row * m_Cols + i];
        }
        return result;
    }

    Matrix Matrix::getCol(int col)
    {
        if (col < 0 || col >= m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        Matrix result(m_Rows, 1);
        for (int i = 0; i < m_Rows; i++) {
            result(i, 0) = m_Data[i * m_Cols + col];
        }
        return result;
    }

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
    Matrix Matrix::getSubMatrix(int row, int col)
    {
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

    Matrix Matrix::dot(Matrix& other)
    {
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

    void Matrix::applyFunction(const std::function<double(double)>& func) {
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), func);
    }

    void Matrix::transpose()
    {
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

    void Matrix::print() const
    {
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

    std::pair<int, int> Matrix::shape()
    {
        return std::pair(m_Rows, m_Cols);
    }

} // meltrix