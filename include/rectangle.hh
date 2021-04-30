#pragma once

#include "size.hh"
#include "vector.hh"
#include "matrix.hh"
#include <iostream>
#include <iomanip>

class Rectangle {

private:

    Vector rect[WIER];   

public:

    Rectangle();

    Rectangle(Vector A, Vector B, Vector C, Vector D);

    const Vector &operator [] (int index) const;

    Vector &operator [] (int index);

    Rectangle Przesuniencie(Vector const Vec);

    Rectangle Obrot(double const kat, int const raz);

    void Dlugosc();
};

std::ostream &operator << (std::ostream &out, Rectangle const &tmp);

