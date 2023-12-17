#include <catch2/catch_test_macros.hpp>
#include "MatrixBase.h"

TEST_CASE("Basic scalar matrix operations", "[matrix]") {
    using namespace meltrix;

    SECTION("Scalar Addition") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m1](){
            Matrix r1 = m1 + 2;
            REQUIRE(r1 == Matrix(2, 2, {3, 4, 5, 6}));
        }());
    }

    SECTION("Scalar Subtraction") {
        Matrix m2 = Matrix(2, 2, {1,2,3,4});
        REQUIRE_NOTHROW([&m2](){
            Matrix r2 = m2 - 2;
            REQUIRE(r2 == Matrix(2, 2, {-1, 0, 1, 2}));
        }());
    }

    SECTION("Scalar Multiplication") {
        Matrix m3 = Matrix(2, 2, {2, 3, 4, 5});
        REQUIRE_NOTHROW([&m3](){
            Matrix r3 = m3 * -1;
            REQUIRE(r3 == Matrix(2, 2, {-2,-3,-4,-5}));
        }());
    }

    SECTION("Scalar Division") {
        Matrix m4 = Matrix(2, 2, {4, 6, 8, 10});
        REQUIRE_NOTHROW([&m4](){
            Matrix r4 = m4 / 2;
            REQUIRE(r4 == Matrix(2, 2, {2, 3, 4, 5}));
        }());
    }
}

TEST_CASE("Inline matrix operations", "[matrix]") {
    using namespace meltrix;

    SECTION("Inline Matrix Addition") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = Matrix(2, 2, {5, 6, 7, 8});
        REQUIRE_NOTHROW([&m1, &m2]() {
            m1 += m2;
            REQUIRE(m1 == Matrix(2, 2, {6, 8, 10, 12}));
        }());
    }

    SECTION("Inline Matrix Subtraction") {
        Matrix m3 = Matrix(2, 2, {5, 6, 7, 8});
        Matrix m4 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m3, &m4]() {
            m3 -= m4;
            REQUIRE(m3 == Matrix(2, 2, {4, 4, 4, 4}));
        }());
    }

    SECTION("Inline Scalar Addition") {
        Matrix m5 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m5]() {
            m5 += 2;
            REQUIRE(m5 == Matrix(2, 2, {3, 4, 5, 6}));
        }());
    }

    SECTION("Inline Scalar Subtraction") {
        Matrix m6 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m6]() {
            m6 -= 2;
            REQUIRE(m6 == Matrix(2, 2, {-1, 0, 1, 2}));
        }());
    }

    SECTION("Inline Scalar Multiplication") {
        Matrix m7 = Matrix(2, 2, {2, 3, 4, 5});
        REQUIRE_NOTHROW([&m7]() {
            m7 *= -1;
            REQUIRE(m7 == Matrix(2, 2, {-2, -3, -4, -5}));
        }());
    }

    SECTION("Inline Scalar Division") {
        Matrix m8 = Matrix(2, 2, {4, 6, 8, 10});
        REQUIRE_NOTHROW([&m8]() {
            m8 /= 2;
            REQUIRE(m8 == Matrix(2, 2, {2, 3, 4, 5}));
        }());
    }
}

TEST_CASE("Basic matrix operations", "[matrix]") {
    using namespace meltrix;
    
    SECTION("Matrix Addition") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = Matrix(2, 2, {5, 6, 7, 8});
        REQUIRE_NOTHROW([&m1, &m2](){
            Matrix r1 = m1 + m2;
            REQUIRE(r1 == Matrix(2, 2, {6, 8, 10, 12}));
        }());
    }

    SECTION("Matrix Subtraction") {
        Matrix m3 = Matrix(2, 2, {5, 6, 7, 8});
        Matrix m4 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m3, &m4](){
            Matrix r2 = m3 - m4;
            REQUIRE(r2 == Matrix(2, 2, {4, 4, 4, 4}));
        }());
    }
}

TEST_CASE("Basic inline matrix operations", "[matrix]") {
    using namespace meltrix;
     SECTION("Inline Matrix Addition") {
        Matrix m1 = Matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = Matrix(2, 2, {5, 6, 7, 8});
        REQUIRE_NOTHROW([&m1, &m2]() {
            m1 += m2;
            REQUIRE(m1 == Matrix(2, 2, {6, 8, 10, 12}));
        }());
    }

    SECTION("Inline Matrix Subtraction") {
        Matrix m3 = Matrix(2, 2, {5, 6, 7, 8});
        Matrix m4 = Matrix(2, 2, {1, 2, 3, 4});
        REQUIRE_NOTHROW([&m3, &m4]() {
            m3 -= m4;
            REQUIRE(m3 == Matrix(2, 2, {4, 4, 4, 4}));
        }());
    }
}