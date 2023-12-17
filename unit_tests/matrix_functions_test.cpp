#include <catch2/catch_test_macros.hpp>
#include "MatrixBase.h"

TEST_CASE("Matrix functions", "[matrix]") {
    using namespace meltrix;

    SECTION("Matrix Determinant") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m1](){
            double r1 = m1.determinant();
            REQUIRE(r1 == -2);
        }());

        Matrix m2 = Matrix(2, 2, {3, 8, 4, 6});
        REQUIRE_NOTHROW([&m2](){
            double r2 = m2.determinant();
            REQUIRE(r2 == -14);
        }());

        Matrix m3 = Matrix(1, 1, {2});
        REQUIRE_NOTHROW([&m3](){
            double r3 = m3.determinant();
            REQUIRE(r3 == 2);
        }());

        Matrix m4 = Matrix(1, 3, {1, 2, 3});
        REQUIRE_THROWS([&m4](){
            double r4 = m4.determinant();
        }());
    }
}