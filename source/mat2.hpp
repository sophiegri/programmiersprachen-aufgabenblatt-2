#ifndef MAT2_HPP
#define MAT2_HPP

struct Mat2
{
//Aufgabe 2.5

Mat2 (); //Standardkonstruktor
Mat2 (float _a, float _b, float _c, float _d); //User Konstruktor 

float a; 
float b; 
float c; 
float d;

Mat2& operator*=(Mat2 const& m); 
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2); 

#endif