#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

struct Mat2
{
//Aufgabe 2.5

Mat2 (); //Standardkonstruktor
Mat2 (float _a, float _b, float _c, float _d); //User Konstruktor 

float a; //Top left
float b; //Top right
float c; //Down left
float d; //Down right

Mat2& operator*=(Mat2 const& m); 

float det() const; 
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2); 
Mat2 operator*(Mat2 const& m, float s); 
Mat2 operator*(float s, Mat2 const& m); //Multiplikation mit float

//Aufgabe 2.6 

Vec2 operator*(Mat2 const& m, Vec2 const& v);
Vec2 operator*(Vec2 const& v, Mat2 const& m);
Mat2 inverse (Mat2 const& m);
Mat2 transpose (Mat2 const& m);
Mat2 make_rotation_mat2 (float phi);

#endif