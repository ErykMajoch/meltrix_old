#include "meltrix.h"

#include <iostream>
#include <cmath>

int main() {
    using namespace meltrix;
    Matrix m = Matrix(2, 2, {1, 2, 3, 4});
    std::cout << "Matrix successfully created!\n";
    return 0;
}
