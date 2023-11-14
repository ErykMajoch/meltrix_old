#include <catch2/catch_test_macros.hpp>
#include "MatrixBase.h"

TEST_CASE("Matrix Comparison Tests", "[matrix]") {
    using namespace meltrix;

    SECTION("Matrix Equality") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE(m1 == m2);

        Matrix m3 = Matrix(2, 2, {1, 2, 3, 5});
        REQUIRE_FALSE(m1 == m3);
    }

    SECTION("Matrix Inequality") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_FALSE(m1 != m2);

        Matrix m3 = Matrix(2, 2, {1, 2, 3, 5});
        REQUIRE(m1 != m3);
    }
}