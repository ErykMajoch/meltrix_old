#include "meltrix.h"

#include <iostream>
#include <cmath>

int main() {
    using namespace meltrix;
    Matrix m = Matrix(4, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    std::cout << "Current matrix:\n";
    m.print();

    std::cout << "\nAfter transposition:\n";
    m.transpose();
    m.print();

    return 0;
}
