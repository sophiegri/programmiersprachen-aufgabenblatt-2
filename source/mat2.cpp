#include "mat2.hpp"
#include <iostream>

//Aufgabe 2.5

Mat2::Mat2 (): //Standardkonstruktor legt Einheitsmatrix an
  a{1.0},
  b{0.0},
  c{0.0},
  d{1.0}
  {}

Mat2::Mat2 (float _a, float _b, float _c, float _d): //User Konstruktor mit 4 Variablen
  a{_a},
  b{_b},
  c{_c},
  d{_d}
  {}


Mat2& Mat2::operator*=(Mat2 const& m) //Methode der Multiplikation
{
 a*=m.a;
 b*=m.b;
 c*=m.c;
 d*=m.d;
 return *this; 
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2) //Freie Funktion zur Multiplikation
{
 Mat2 result {m1};
 result *= m2;
 return result;
}
