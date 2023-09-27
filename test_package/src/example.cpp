#include "meltrix.h"

#include <iostream>

int main() {
    using namespace meltrix;

    std::cout << "Uniform Distribution: \n";
    Matrix m = RandomMatrix(3, 3, meltrix::UNIFORM);
    m.print();

    std::cout << "Binomial Distribution: \n";
    Matrix m2 = RandomMatrix(3, 3, meltrix::BINOMIAL);
    m2.print();

    std::cout << "Normal Distribution: \n";
    Matrix m3 = RandomMatrix(3, 3, meltrix::NORMAL);
    m3.print();

    return 0;
}
