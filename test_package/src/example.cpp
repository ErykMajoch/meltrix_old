#include "meltrix.h"

#include <iostream>

int main() {
    using namespace meltrix;
    Matrix m = IdentityMatrix(4);
    Matrix m2 = Matrix(4, 4, {
        1.001, 2, 3, 4,
        5, 63, 7, 8,
        9, 10.00000322, 11, 12,
        13, 14, 15, 16133.233
    });
    Matrix m3 = Matrix(3, 5, 0.00212);

    m.print();
    std::cout << "\n";
    m2.print();
    std::cout << "\n";
    m3.print();
    return 0;
}
