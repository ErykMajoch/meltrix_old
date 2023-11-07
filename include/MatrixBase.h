#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>

namespace meltrix {

    class Matrix {
    public:

        // Matrix Constructors
        Matrix() = default;
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, const double& value);
        Matrix(int rows, int cols, const std::vector<double>& data);
        Matrix(const Matrix& other);

        // Matrix Comparison
        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const;

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
        Matrix getSubMatrix(int row, int col);

        // Matrix Functions
        Matrix dot(Matrix& other);
        void applyFunction(const std::function<double(double)>& func);
        void transpose();

        // Utility Functions
        void print() const;
        std::pair<int, int> shape();

        // Destructor
        ~Matrix() = default;

    protected:
        int m_Rows = 0;
        int m_Cols = 0;
        std::vector<double> m_Data = {};
    };

} // meltrix