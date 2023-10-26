#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>

namespace meltrix {

    /// <summary>
    /// The base matrix class
    /// </summary>
    class Matrix {
    public:

        // Constructors
        Matrix() = default;
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, const double& value);
        Matrix(int rows, int cols, const std::vector<double>& data);
        Matrix(const Matrix& other);

        // Scalar Operations
        Matrix operator+(const double& scalar) const;
        Matrix operator-(const double& scalar) const;
        Matrix operator*(const double& scalar) const;
        void operator+=(const double& scalar);
        void operator-=(const double& scalar);
        void operator*=(const double& scalar);

        // Matrix Operations
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        void operator+=(const Matrix& other);
        void operator-=(const Matrix& other);

        // Accessors
        double& operator()(int row, int col);
        Matrix getRow(int row);
        Matrix getCol(int col);
        Matrix getSubMatrix(int rowStart, int rowEnd, int colStart, int colEnd);

        // Matrix Functions
        Matrix dot(Matrix& other);
        void applyFunction(const std::function<double(double)>& func);

        // Utility Functions
        void print() const;

        // Destructor
        ~Matrix() = default;

    protected:
        unsigned int m_Rows = 0;
        unsigned int m_Cols = 0;
        std::vector<double> m_Data = {};
    };

} // meltrix