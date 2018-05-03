#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

//Aufgabe 2.2

TEST_CASE ("Standardkonstruktor_Vec")
{
  Vec2 vector1;
  REQUIRE (vector1.x == 0);
  REQUIRE (vector1.y == 0);
}

TEST_CASE ("User_Konstruktor_Vec")
{
  Vec2 vector1 {1,2};
  REQUIRE (vector1.x == 1);
  REQUIRE (vector1.y == 2);
}

TEST_CASE ("Konstruktoren" "Vector" ,"[vec]")
{
  Vec2 vector1 {}; //Hier wird ein Objekt mit dem Standardkonstruktor angelegt 
  Vec2 vector2 {2.4,1.5}; //Hier wird ein Objekt mit dem Konstruktor erstellt
  REQUIRE (Vec2 (2.4, 1.5).x == Approx(2.4).epsilon(0.01));
  REQUIRE (vector2.x == Approx (2.4).epsilon(0.01));
  REQUIRE (Vec2 (-9.7, 9.0).y == Approx(9.0).epsilon(0.01));
  REQUIRE (vector1.y == Approx (0.0).epsilon(0.01));
}

//Aufgabe 2.3

TEST_CASE ("Vektoraddition" ,"[vec]" "[addition]")
{
 Vec2 vector1 {4.5, 8.9};
 Vec2 vector2 {2.8, 0.5}; 
 vector1+=vector2;
 REQUIRE (vector1.x== Approx(7.3f).epsilon(0.01));
 REQUIRE (vector1.y== Approx(9.4f).epsilon(0.01));

 Vec2 vector3 {0.0, -4.7};
 Vec2 vector4 {0.2, -5}; 
 vector3+=vector4;
 REQUIRE (vector3.x== Approx(0.2f).epsilon(0.01));
 REQUIRE (vector3.y== Approx(-9.7f).epsilon(0.01));
}

TEST_CASE ("Vektorsubtraktion" ,"[vec]" "[subtraktion]")
{
 Vec2 vector1 {4.5, 8.9};
 Vec2 vector2 {2.8, 0.5}; 
 vector1-=vector2;

 REQUIRE (vector1.x== Approx (1.7f).epsilon(0.01));
 REQUIRE (vector1.y== Approx (8.4f).epsilon(0.01));

 Vec2 vector3 {0.0, -4.7};
 Vec2 vector4 {0.2, -5}; 
 vector3-=vector4;
 REQUIRE (vector3.x== Approx (-0.2f).epsilon(0.01));
 REQUIRE (vector3.y== Approx (0.3f).epsilon(0.01));
}

TEST_CASE ("Vektormultiplikation" ,"[vec]" "[multiplikation]")
{
 Vec2 vector1 {4.5, 8.9};
 float s = 9.0f;
 vector1 *= s;

 REQUIRE (vector1.x== Approx (40.5f).epsilon(0.01));
 REQUIRE (vector1.y== Approx (80.1f).epsilon(0.01));

 Vec2 vector2 {0.0, -4.7}; 
 float p = -4.8f;
 vector2 *= p;
 REQUIRE (vector2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (vector2.y== Approx (22.56f).epsilon(0.01));
}

TEST_CASE ("Vektordivision" ,"[vec]" "[division]")
{
 Vec2 vector1 {4.5, 8.9};
 float s = 9.0f;
 vector1 /= s;

 REQUIRE (vector1.x== Approx (0.5f).epsilon(0.01));
 REQUIRE (vector1.y== Approx (0.98f).epsilon(0.01));

 Vec2 vector2 {0.0, -4.7}; 
 float p = -4.8f;
 vector2 /= p;
 REQUIRE (vector2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (vector2.y== Approx (0.97f).epsilon(0.01));

 Vec2 vector3 {0.4, 3}; 
 float q = 0.0f;
 vector2 /= q;
 REQUIRE (vector3.x== Approx (vector3.x).epsilon(0.01));
 REQUIRE (vector3.y== Approx (vector3.y).epsilon(0.01));
}

//Aufgabe 2.4 

TEST_CASE ("Addition" ,"[vec]" "[addition]")
{
 Vec2 vector1 {4.5, 8.9}; //entspricht u
 Vec2 vector2 {2.8, 0.5}; //entspricht v
 Vec2 result1 {}; //der Vektor indem das Ergebnis gespeichert wird
 result1 = vector1+vector2;
 REQUIRE (result1.x== Approx(7.3f).epsilon(0.01));
 REQUIRE (result1.y== Approx(9.4f).epsilon(0.01));

 Vec2 vector3 {0.0, -4.7};
 Vec2 vector4 {0.2, -5}; 
 Vec2 result2 {};
 result2 = vector3+vector4;
 REQUIRE (result2.x== Approx(0.2f).epsilon(0.01));
 REQUIRE (result2.y== Approx(-9.7f).epsilon(0.01));
}

TEST_CASE ("Subtraktion" ,"[vec]" "[subtraktion]")
{
 Vec2 vector1 {4.5, 8.9}; 
 Vec2 vector2 {2.8, 0.5}; 
 Vec2 result1 {}; 
 result1 = vector1-vector2;
 REQUIRE (result1.x== Approx(1.7f).epsilon(0.01));
 REQUIRE (result1.y== Approx(8.4f).epsilon(0.01));

 Vec2 vector3 {0.0, -4.7};
 Vec2 vector4 {0.2, -5}; 
 Vec2 result2 {};
 result2 = vector3-vector4;
 REQUIRE (result2.x== Approx(-0.2f).epsilon(0.01));
 REQUIRE (result2.y== Approx(0.3f).epsilon(0.01));
}

TEST_CASE ("Multiplikation" ,"[vec]" "[multiplikation]")
{
 Vec2 vector1 {4.5, 8.9}; //entspricht v
 float s = 9.0f;
 Vec2 result1 {};
 result1 = vector1 * s;
  REQUIRE (result1.x== Approx (40.5f).epsilon(0.01));
 REQUIRE (result1.y== Approx (80.1f).epsilon(0.01));

 Vec2 vector2 {0.0, -4.7}; 
 float p = -4.8f;
 Vec2 result2 {};
 result2 = vector2 * p;
 REQUIRE (result2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (result2.y== Approx (22.56f).epsilon(0.01));
}

TEST_CASE ("Division" ,"[vec]" "[division]")
{
 Vec2 vector1 {4.5, 8.9}; //entspricht v
 float s = 9.0f; //entspricht s 
 Vec2 result1 {};
 result1 = vector1 / s;
 REQUIRE (result1.x== Approx (0.5f).epsilon(0.01));
 REQUIRE (result1.y== Approx (0.98f).epsilon(0.01));

 Vec2 vector2 {0.0, -4.7}; 
 float p = -4.8f;
 Vec2 result2 {};
 result2 = vector2 / p;
 REQUIRE (result2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (result2.y== Approx (0.97f).epsilon(0.01));

 Vec2 vector3 {0.4, 3}; 
 float q = 0.0f;
 Vec2 result3 {};
 result3 = vector3 / q;
 REQUIRE (result3.x== Approx (vector3.x).epsilon(0.01));
 REQUIRE (result3.y== Approx (vector3.y).epsilon(0.01));
}

TEST_CASE ("Multiplikation2" ,"[vec]" "[multiplikation]")
{
 Vec2 vector1 {4.5, 8.9}; //entspricht v
 float s = 9.0f;
 Vec2 result1 {};
 result1 = s * vector1;
 REQUIRE (result1.x== Approx (40.5f).epsilon(0.01));
 REQUIRE (result1.y== Approx (80.1f).epsilon(0.01));

 Vec2 vector2 {0.0, -4.7}; 
 float p = -4.8f;
 Vec2 result2 {};
 result2 = p * vector2;
 REQUIRE (result2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (result2.y== Approx (22.56f).epsilon(0.01));
}

//Aufgabe 2.5

TEST_CASE ("Standardkonstruktor_Mat" , "[mat]")
{
  Mat2 matrix1;
  REQUIRE (matrix1.a == 1);
  REQUIRE (matrix1.b == 0);
  REQUIRE (matrix1.c == 0);
  REQUIRE (matrix1.d == 1);
}

TEST_CASE ("User_Konstruktor_Mat" , "[mat]")
{
  Mat2 matrix1 {1,2,3,4};  
  REQUIRE (matrix1.a == 1);
  REQUIRE (matrix1.b == 2);
  REQUIRE (matrix1.c == 3);
  REQUIRE (matrix1.d == 4);

  Mat2 matrix2 {1.78f,-23,0.9,40};  
  REQUIRE (matrix2.a == Approx (1.78f).epsilon(0.01));
  REQUIRE (matrix2.b == -23);
  REQUIRE (matrix2.c == Approx (0.9).epsilon(0.01));
  REQUIRE (matrix2.d == 40);
}

TEST_CASE ("Konstruktoren" "Matrix" ,"[mat]")
{
  Vec2 vector1 {}; //Hier wird ein Objekt mit dem Standardkonstruktor angelegt 
  Vec2 vector2 {2.4,1.5}; //Hier wird ein Objekt mit dem Konstruktor erstellt
  REQUIRE (Vec2 (2.4, 1.5).x == Approx(2.4).epsilon(0.01));
  REQUIRE (vector2.x == Approx (2.4).epsilon(0.01));
  REQUIRE (Vec2 (-9.7, 9.0).y == Approx(9.0).epsilon(0.01));
  REQUIRE (vector1.y == Approx (0.0).epsilon(0.01));
}

TEST_CASE ("Matrizenmultiplikation" ,"[mat]" "[multiplikation]")
{
 Mat2 matrix1 {4, 8, 1, 2}; //entspricht m
 Mat2 matrix2 {2, 3, 4, 5};
 matrix1 *= matrix2;
 REQUIRE (matrix1.a== Approx (8.0f).epsilon(0.01));
 REQUIRE (matrix1.b== Approx (24.0f).epsilon(0.01));
 REQUIRE (matrix1.c== Approx (4.0f).epsilon(0.01));
 REQUIRE (matrix1.d== Approx (10.0f).epsilon(0.01));
}

TEST_CASE ("Matrizenmultiplikation2" ,"[mat]" "[multiplikation]")
{
 Mat2 matrix1 {4, 8, 1, 2}; //entspricht m1
 Mat2 matrix2 {2, 3, 4, 5}; //entspricht m2
 Mat2 result1 {};
 result1 = matrix1 * matrix2;
 REQUIRE (result1.a== Approx (8.0f).epsilon(0.01));
 REQUIRE (result1.b== Approx (24.0f).epsilon(0.01));
 REQUIRE (result1.c== Approx (4.0f).epsilon(0.01));
 REQUIRE (result1.d== Approx (10.0f).epsilon(0.01));

 Mat2 matrix3 {-40, 23, 0.01, -0.2}; //entspricht m1
 Mat2 matrix4 {2.0, 2.03, -4, 5.6}; //entspricht m2
 Mat2 result2 {};
 result2 = matrix3 * matrix4;
 REQUIRE (result2.a== Approx (-80.0f).epsilon(0.01));
 REQUIRE (result2.b== Approx (46.69f).epsilon(0.01));
 REQUIRE (result2.c== Approx (-0.04f).epsilon(0.01));
 REQUIRE (result2.d== Approx (-1.12f).epsilon(0.01));
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

