#include "meltrix.h"

#include <iostream>
#include <cmath>

int main() {
    using namespace meltrix;
    Matrix m = Matrix(4, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

    std::cout << "Current matrix:\n";
    m.print();

    m.applyFunction([](double a) {return std::sin(a);});

    std::cout << "\nAfter function:\n";
    m.print();

    return 0;
}
