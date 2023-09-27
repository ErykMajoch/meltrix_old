#include "meltrix.h"

#include <iostream>

int main() {
    using namespace meltrix;

    Matrix m1 = IdentityMatrix(4);

    Matrix m2 = Matrix(4, 3, {
        13, 9, 7,
        8, 7, 4,
        6, 4, 0,
        2, 4, 1
    });

    Matrix m3 = m1.dot(m2);
    m3.print();

    return 0;
}
