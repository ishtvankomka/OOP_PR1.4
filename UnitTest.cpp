#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "1.4/Vector.cpp"
#include "1.4/Vector.hpp"

TEST_CASE( "Arguments initialized") {
    int a = 1;
    int b = 10000;
    Vector testing1;
    REQUIRE( testing1.Init(a) == true);
    REQUIRE( testing1.Init(b) == true);
}
