#include "meltrix.h"

#include <iostream>
#include <cmath>

int main() {
    using namespace meltrix;
    Matrix m = Matrix(4, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    std::cout << "Current matrix:\n";
    m.print();

    Matrix m2 = m.getSubMatrix(1, 2);
    std::cout << "\nSub matrix from [1,2]:\n";
    m2.print();

    return 0;
}
