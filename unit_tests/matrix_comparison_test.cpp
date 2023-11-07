#include <catch2/catch_test_macros.hpp>
#include "MatrixBase.h"

TEST_CASE("Matrix Comparison Tests", "[matrix]") {
    using namespace meltrix;

    SECTION("Equality") {
        Matrix a = Matrix(2, 3, 9);
        Matrix b = Matrix(2, 3, 9);
        REQUIRE(a == b);
    }

    SECTION("Inequality") {
        Matrix c = Matrix(2, 3, 9);
        Matrix d = Matrix(3, 2, 9);
        REQUIRE(c != d);
    }

}