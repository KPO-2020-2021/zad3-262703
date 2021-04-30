#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/vector.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("Operator indeks2"){
    Vector tmpV;
    double a = 3, b = 4;
    tmpV[0] = a;
    tmpV[1] = b;
    CHECK(tmpV[0] == 3 && tmpV[1] == 4);
}