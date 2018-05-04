#include "mat2.hpp"
#include <iostream>
#include <cmath>

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
 a = a*m.a+b*m.c;
 b = a*m.b+b*m.d;
 c = c*m.a+d*m.c;
 d = c*m.b+d*m.d;
 return *this; 
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2) //Freie Funktion zur Multiplikation
{
 Mat2 result {};
 result.a = {m1.a*m2.a+m1.b*m2.c};
 result.b = {m1.a*m2.b+m1.b*m2.d};
 result.c = {m1.c*m2.a+m1.d*m2.c};
 result.d = {m1.c*m2.b+m1.d*m2.d};
 return result;
}

//Aufgabe 2.6

float Mat2::det () const  //Methode, um Determinante zu berechnen 
{
 float det=(a*d)-(b*c); 
 return det; 
}  
//const sagt an, dass an der Matrix nichts veraendert wird.
//det ist eine Methode in der Mat2 Klasse/Struct. Sie bekommt nichts uebergeben, da sie eine Methode des struct ist


Mat2 operator*(Mat2 const& m, float s) //Matrixmultiplikation mit einem float 
{
  Mat2 new_mat {m.a*s, m.b*s, m.c*s, m.d*s};   
  return new_mat;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v) //Multiplikation Matrix und Vektor
{
 Vec2 result; 
 result.x ={m.a*v.x+m.b*v.y};
 result.y ={m.c*v.x+m.d*v.y};
 return result;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m) //Multiplikation Vektor und Matrix 
{
 Vec2 result; 
 result.x ={v.x*m.a+v.y*m.c};
 result.y ={v.x*m.b+v.y*m.d};
 return result;
} 

Mat2 operator*(float s, Mat2 const& m) //Matrixmultiplikation mit einem float 
{
  Mat2 new_mat {m.a*s, m.b*s, m.c*s, m.d*s};   
  return new_mat;
}

Mat2 inverse (Mat2 const& m) //Inverse Berechnung
{
 Mat2 m1 {m.d,m.b*-1,m.c*-1,m.a};
 Mat2 inverse = 1/(m.det())*(m1);
 return inverse;
}

Mat2 transpose (Mat2 const& m)
{
 Mat2 transpose1 {m.a, m.c, m.b, m.d};
 return transpose1;
}

Mat2 make_rotation_mat2 (float phi)
{
 Mat2 m1 {cos(phi), -sin(phi), sin(phi), cos(phi)};
 return m1;
}

