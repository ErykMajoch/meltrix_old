#include <catch2/catch_test_macros.hpp>
#include "MatrixBase.h"

TEST_CASE("Default matrix initialisation", "[matrix]") {
using namespace meltrix;

SECTION("Negative sizes") {
REQUIRE_THROWS([](){
Matrix a = Matrix(-1, -3);
}());
}

SECTION("No initial value") {
Matrix b = Matrix(2, 3);
std::pair<int, int> s1 = b.shape();
REQUIRE(s1
.first == 2);
REQUIRE(s1
.second == 3);
}

SECTION("With initial value") {
Matrix c = Matrix(2, 3, 9);
std::pair<int, int> s2 = c.shape();
REQUIRE(s2
.first == 2);
REQUIRE(s2
.second == 3);
REQUIRE(c(1, 1)
== 9);
}

SECTION("With initial values from vector") {
std::vector<double> data = {1, 2, 3, 4, 5, 6};
REQUIRE_NOTHROW([&data](){
Matrix d = Matrix(2, 3, data);
}());

REQUIRE_THROWS([&data](){
Matrix e = Matrix(3, 3, data);
}());
}

SECTION("From another matrix") {
Matrix f = Matrix(3, 2);
REQUIRE_NOTHROW([&f](){
Matrix g = Matrix(f);
}());
}

}