#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/vector.hh"

TEST_CASE("Konstr Bezparm"){
    Vector tmpV = Vector();
    CHECK((tmpV[0] == 0) && (tmpV[1] == 0));
}

TEST_CASE("Konstr Param"){
    double Vek[] = {3.0, 4.0};
    Vector tmpV = Vector(Vek);
    CHECK(tmpV[0] == 3 && tmpV[1] == 4);

}

TEST_CASE("Operator indeks1"){
    double Vek[] = {3.0, 4.0};
    Vector tmpV = Vector(Vek);
    double a = tmpV[0], b = tmpV[1];
    CHECK(((a == 3)&&(b == 4)));
}

TEST_CASE("Operator indeks2"){
    Vector tmpV;
    double a = 3, b = 4;
    tmpV[0] = a;
    tmpV[1] = b;
    CHECK(tmpV[0] == 3 && tmpV[1] == 4);
}

TEST_CASE("Dodawanie"){
    Vector tmpV, tmpV1, tmpV2;
    double a[] = {3.0, 4.0};
    tmpV1 = Vector(a);
    tmpV2 = Vector(a);
    tmpV = tmpV1 + tmpV2;
    CHECK(tmpV[0] == 6 && tmpV[1] == 8);
}

TEST_CASE("Odejmowanie"){
    Vector tmpV, tmpV1, tmpV2;
    double a[] = {3.0, 4.0};
    double b[] = {2.0, 2.0};
    tmpV1 = Vector(a);
    tmpV2 = Vector(b);
    tmpV = tmpV1 - tmpV2;
    CHECK(tmpV[0] == 1 && tmpV[1] == 2);
}

TEST_CASE("Dzielenie"){
    Vector tmpV, tmpV1;
    double a[] = {3.0, 4.0};
    double b = 2;
    tmpV1 = Vector(a);
    tmpV = tmpV1 / b;
    CHECK(tmpV[0] == 1.5 && tmpV[1] == 2);
}

TEST_CASE("Dzielenie przez zero"){
    Vector tmpV, tmpV1;
    double a[] = {3.0, 4.0};
    double b = 0;
    tmpV1 = Vector(a);
    WARN_THROWS(tmpV = tmpV1 / b);
}


