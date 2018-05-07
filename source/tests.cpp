#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <cmath>


//Aufgabe 2.2

TEST_CASE ("Standardkonstruktor_Vec")
{
  Vec2 vector1;
  REQUIRE (vector1.x == 0.0f);
  REQUIRE (vector1.y == 0.0f);
}

TEST_CASE ("User_Konstruktor_Vec")
{
  Vec2 vector1 {1.0f,2.0f};
  REQUIRE (vector1.x == 1.0f);
  REQUIRE (vector1.y == 2.0f);
}

TEST_CASE ("Konstruktoren" "Vector" ,"[vec]")
{
  Vec2 vector1 {}; //Hier wird ein Objekt mit dem Standardkonstruktor angelegt 
  Vec2 vector2 {2.4f,1.5f}; //Hier wird ein Objekt mit dem Konstruktor erstellt
  REQUIRE (Vec2 (2.4f, 1.5f).x == Approx(2.4f).epsilon(0.01));
  REQUIRE (vector2.x == Approx (2.4f).epsilon(0.01));
  REQUIRE (Vec2 (-9.7f, 9.0f).y == Approx(9.0f).epsilon(0.01));
  REQUIRE (vector1.y == Approx (0.0f).epsilon(0.01));
}

//Aufgabe 2.3

TEST_CASE ("Vektoraddition" ,"[vec]" "[addition]")
{
 Vec2 vector1 {4.5f, 8.9f};
 Vec2 vector2 {2.8f, 0.5f}; 
 vector1+=vector2;
 REQUIRE (vector1.x== Approx(7.3f).epsilon(0.01));
 REQUIRE (vector1.y== Approx(9.4f).epsilon(0.01));

 Vec2 vector3 {0.0f, -4.7f};
 Vec2 vector4 {0.2f, -5.0f}; 
 vector3+=vector4;
 REQUIRE (vector3.x== Approx(0.2f).epsilon(0.01));
 REQUIRE (vector3.y== Approx(-9.7f).epsilon(0.01));
}

TEST_CASE ("Vektorsubtraktion" ,"[vec]" "[subtraktion]")
{
 Vec2 vector1 {4.5f, 8.9f};
 Vec2 vector2 {2.8f, 0.5f}; 
 vector1-=vector2;

 REQUIRE (vector1.x== Approx (1.7f).epsilon(0.01));
 REQUIRE (vector1.y== Approx (8.4f).epsilon(0.01));

 Vec2 vector3 {0.0f, -4.7f};
 Vec2 vector4 {0.2f, -5.0f}; 
 vector3-=vector4;
 REQUIRE (vector3.x== Approx (-0.2f).epsilon(0.01));
 REQUIRE (vector3.y== Approx (0.3f).epsilon(0.01));
}

TEST_CASE ("Vektormultiplikation" ,"[vec]" "[multiplikation]")
{
 Vec2 vector1 {4.5f, 8.9f};
 float s = 9.0f;
 vector1 *= s;

 REQUIRE (vector1.x== Approx (40.5f).epsilon(0.01));
 REQUIRE (vector1.y== Approx (80.1f).epsilon(0.01));

 Vec2 vector2 {0.0f, -4.7f}; 
 float p = -4.8f;
 vector2 *= p;
 REQUIRE (vector2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (vector2.y== Approx (22.56f).epsilon(0.01));
}

TEST_CASE ("Vektordivision" ,"[vec]" "[division]")
{
 Vec2 vector1 {4.5f, 8.9f};
 float s = 9.0f;
 vector1 /= s;

 REQUIRE (vector1.x== Approx (0.5f).epsilon(0.01));
 REQUIRE (vector1.y== Approx (0.98f).epsilon(0.01));

 Vec2 vector2 {0.0f, -4.7f}; 
 float p = -4.8f;
 vector2 /= p;
 REQUIRE (vector2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (vector2.y== Approx (0.97f).epsilon(0.01));

 Vec2 vector3 {0.4f, 3.0f}; 
 float q = 0.0f;
 vector2 /= q;
 REQUIRE (vector3.x== Approx (vector3.x).epsilon(0.01));
 REQUIRE (vector3.y== Approx (vector3.y).epsilon(0.01));
}

//Aufgabe 2.4 

TEST_CASE ("Addition" ,"[vec]" "[addition]")
{
 Vec2 vector1 {4.5f, 8.9f}; //entspricht u
 Vec2 vector2 {2.8f, 0.5f}; //entspricht v
 Vec2 result1 {}; //der Vektor indem das Ergebnis gespeichert wird
 result1 = vector1+vector2;
 REQUIRE (result1.x== Approx(7.3f).epsilon(0.01));
 REQUIRE (result1.y== Approx(9.4f).epsilon(0.01));

 Vec2 vector3 {0.0f, -4.7f};
 Vec2 vector4 {0.2f, -5.0f}; 
 Vec2 result2 {};
 result2 = vector3+vector4;
 REQUIRE (result2.x== Approx(0.2f).epsilon(0.01));
 REQUIRE (result2.y== Approx(-9.7f).epsilon(0.01));
}

TEST_CASE ("Subtraktion" ,"[vec]" "[subtraktion]")
{
 Vec2 vector1 {4.5f, 8.9f}; 
 Vec2 vector2 {2.8f, 0.5f}; 
 Vec2 result1 {}; 
 result1 = vector1-vector2;
 REQUIRE (result1.x== Approx(1.7f).epsilon(0.01));
 REQUIRE (result1.y== Approx(8.4f).epsilon(0.01));

 Vec2 vector3 {0.0f, -4.7f};
 Vec2 vector4 {0.2f, -5.0f}; 
 Vec2 result2 {};
 result2 = vector3-vector4;
 REQUIRE (result2.x== Approx(-0.2f).epsilon(0.01));
 REQUIRE (result2.y== Approx(0.3f).epsilon(0.01));
}

TEST_CASE ("Multiplikation" ,"[vec]" "[multiplikation]")
{
 Vec2 vector1 {4.5f, 8.9f}; //entspricht v
 float s = 9.0f;
 Vec2 result1 {};
 result1 = vector1 * s;
  REQUIRE (result1.x== Approx (40.5f).epsilon(0.01));
 REQUIRE (result1.y== Approx (80.1f).epsilon(0.01));

 Vec2 vector2 {0.0f, -4.7f}; 
 float p = -4.8f;
 Vec2 result2 {};
 result2 = vector2 * p;
 REQUIRE (result2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (result2.y== Approx (22.56f).epsilon(0.01));
}

TEST_CASE ("Division" ,"[vec]" "[division]")
{
 Vec2 vector1 {4.5f, 8.9f}; //entspricht v
 float s = 9.0f; //entspricht s 
 Vec2 result1 {};
 result1 = vector1 / s;
 REQUIRE (result1.x== Approx (0.5f).epsilon(0.01));
 REQUIRE (result1.y== Approx (0.98f).epsilon(0.01));

 Vec2 vector2 {0.0f, -4.7f}; 
 float p = -4.8f;
 Vec2 result2 {};
 result2 = vector2 / p;
 REQUIRE (result2.x== Approx (0.0f).epsilon(0.01));
 REQUIRE (result2.y== Approx (0.97f).epsilon(0.01));

 Vec2 vector3 {0.4f, 3.0f}; 
 float q = 0.0f;
 Vec2 result3 {};
 result3 = vector3 / q;
 REQUIRE (result3.x== Approx (vector3.x).epsilon(0.01));
 REQUIRE (result3.y== Approx (vector3.y).epsilon(0.01));
}

TEST_CASE ("Multiplikation2" ,"[vec]" "[multiplikation]")
{
 Vec2 vector1 {4.5f, 8.9f}; //entspricht v
 float s = 9.0f;
 Vec2 result1 {};
 result1 = s * vector1;
 REQUIRE (result1.x== Approx (40.5f).epsilon(0.01));
 REQUIRE (result1.y== Approx (80.1f).epsilon(0.01));

 Vec2 vector2 {0.0f, -4.7f}; 
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
  REQUIRE (matrix1.a == 1.0f);
  REQUIRE (matrix1.b == 0.0f);
  REQUIRE (matrix1.c == 0.0f);
  REQUIRE (matrix1.d == 1.0f);
}

TEST_CASE ("User_Konstruktor_Mat" , "[mat]")
{
  Mat2 matrix1 {1.0f,2.0f,3.0f,4.0f};  
  REQUIRE (matrix1.a == 1.0f);
  REQUIRE (matrix1.b == 2.0f);
  REQUIRE (matrix1.c == 3.0f);
  REQUIRE (matrix1.d == 4.0f);

  Mat2 matrix2 {1.78f,-23.0f,0.9f,40.0f};  
  REQUIRE (matrix2.a == Approx (1.78f).epsilon(0.01));
  REQUIRE (matrix2.b == -23.0f);
  REQUIRE (matrix2.c == Approx (0.9f).epsilon(0.01));
  REQUIRE (matrix2.d == 40.0f);
}

TEST_CASE ("Konstruktoren" "Matrix" ,"[mat]")
{
  Mat2 matrix1 {}; //Hier wird ein Objekt mit dem Standardkonstruktor angelegt 
  Mat2 matrix2 {2.4f,1.5f,6.9f,3.0f}; //Hier wird ein Objekt mit dem Konstruktor erstellt
  REQUIRE (Mat2 (1.0f,2.0f,3.0f,4.0f).c == Approx(3.0f).epsilon(0.01));
  REQUIRE (matrix2.a == Approx (2.4f).epsilon(0.01));
  REQUIRE (Mat2 (-5.0f,-6.0f,-7.0f,-8.0f).d == Approx(-8).epsilon(0.01));
  REQUIRE (matrix1.c == Approx (0.0f).epsilon(0.01));
}


TEST_CASE ("Matrizenmultiplikation" ,"[mat]" "[multiplikation]")
{
 Mat2 matrix1 {4.0f, 8.0f, 1.0f, 2.0f}; //entspricht m
 Mat2 matrix2 {2.0f, 3.0f, 4.0f, 5.0f};
 Mat2 matrix_neu {};
 matrix_neu.a = ((matrix1.a*matrix2.a)+(matrix1.b*matrix2.c));
 matrix_neu.b = ((matrix1.a*matrix2.b)+(matrix1.b*matrix2.d));
 matrix_neu.c = ((matrix1.c*matrix2.a)+(matrix1.d*matrix2.c));
 matrix_neu.d = ((matrix1.c*matrix2.b)+(matrix1.d*matrix2.d));
 REQUIRE (matrix_neu.a== 40.0f);
 REQUIRE (matrix_neu.b== 52.0f);
 REQUIRE (matrix_neu.c== 10.0f);
 REQUIRE (matrix_neu.d== 13.0f);
}


//Aufgabe 2.6 

TEST_CASE ("Determinantenberechnung" , "[det]")
{
 Mat2 matrix1 {3.0f,2.0f,-5.0f,-1.0f};
 REQUIRE (matrix1.det()== Approx (7.0f).epsilon(0.01));
}

TEST_CASE ("Inversenberechnung", "[inverse]")
{
  Mat2 matrix1 {3.0f,2.0f,-5.0f,-1.0f};
  Mat2 matrix2 {-1.0f, -2.0f, 5.0f, 3.0f};
  Mat2 inverse1 {};
  inverse1 = (1/(matrix1.det())*matrix2);
  REQUIRE (inverse1.a == Approx (-0.14f).epsilon(0.01));
  REQUIRE (inverse1.b == Approx (-0.28f).epsilon(0.01));
  REQUIRE (inverse1.c == Approx (0.71f).epsilon(0.01));
  REQUIRE (inverse1.d == Approx (0.42f).epsilon(0.01));
}

TEST_CASE ("Matrix_Vektor_Multiplikation", "[matvek]")
{
  Mat2 matrix1 {1.0f,2.0f,3.0f,4.0f};
  Vec2 vector1 {2.3f,8.0f};  
  Vec2 produkt1 {};
  produkt1.x= (matrix1.a*vector1.x)+(matrix1.b*vector1.y);
  produkt1.y= (matrix1.c*vector1.x)+(matrix1.d*vector1.y);
  REQUIRE (produkt1.x == Approx (18.3f).epsilon(0.01));
  REQUIRE (produkt1.y == Approx (38.9f).epsilon(0.01));  
}

TEST_CASE ("Vektor_Matrix_Multiplikation", "[vekmat]")
{
 Vec2 vector2 {2.0f,5.0f};
 Mat2 matrix2 {1.0f,2.0f,3.0f,4.0f};
 Vec2 produkt2 {};
 produkt2.x= (vector2.x*matrix2.a)+(vector2.y*matrix2.c);
 produkt2.y= (vector2.x*matrix2.b)+(vector2.y*matrix2.d);
 REQUIRE (produkt2.x == 17.0f);
 REQUIRE (produkt2.y == 24.0f);
}

TEST_CASE ("Transponierte", "[matrix]")
{
 Mat2 m {1.0f,2.0f,3.0f,4.0f};
 Mat2 m1 = transpose (m); //Aufruf der Funktion, um die Matrix zu transponieren
 REQUIRE (m1.b == 3.0f);
 REQUIRE (m1.a == 1.0f);
 REQUIRE (m1.c == 2.0f); 
}

TEST_CASE ("Roationsmatrix" , "[rotation]")
{
  Mat2 rotation_m1 = make_rotation_mat2 (M_PI); //Funktionsaufruf 
  REQUIRE (rotation_m1.a == Approx (-0.99f).epsilon (0.01));
  REQUIRE (rotation_m1.b == Approx (-0.0f).epsilon (0.01));
  REQUIRE (rotation_m1.c == Approx (0.0f).epsilon (0.01));
} 

//Aufgabe 2.7

TEST_CASE ("Farbintensitaet" , "[color]")
{
  Color black {0.0f};
  Color red {0.8f,0.0f,1.3f};
  REQUIRE (black.r == 0.0f);
  REQUIRE (black.g == 0.0f);
  REQUIRE (black.b == 0.0f);

  REQUIRE (red.r == 0.0f); //Hier wird alles auf 0 gesetzt, weil die Farbeingabe falsch war 
  REQUIRE (red.g == 0.0f);
  REQUIRE (red.b == 0.0f);
}

//Aufgabe 2.8 

TEST_CASE ("Circle" ,"[cir]")
{
  Circle circle1 {};
  REQUIRE (circle1.get_radius() == 1.0f);
  REQUIRE (circle1.get_color ().r == 0.0f);
  REQUIRE (circle1.get_center ().x == 0.0f);
  
  Vec2 vector1 {2.0f,2.0f};
  Color color1 {0.0f, 0.0f, 1.0f};
  REQUIRE (color1.b == 1.0f);
  Circle circle2 {4.0f, vector1, color1};  
  REQUIRE (circle2.get_radius() == 4.0f);
  REQUIRE (circle2.get_color ().b == 1.0f);
  REQUIRE (circle2.get_center ().y == 2.0f);
}

TEST_CASE ("Rectangle", "[rec]")
{ 
  Rectangle rectangle1 {};
  REQUIRE (rectangle1.get_width () == 1.0f);
  REQUIRE (rectangle1.get_height () == 1.0f);
  REQUIRE (rectangle1.get_area () == 1.0f);
  REQUIRE (rectangle1.get_color ().b == 0.0f);

  Vec2 max_height1 {4.0f, 8.0f};
  Vec2 min_height1 {0.0f,1.0f};
  Color color2 {1.0f,0.0f,1.0f};
  REQUIRE (color2.r == 1.0f);
  Rectangle rectangle2 {max_height1, min_height1, color2};
  REQUIRE (rectangle2.get_width () == 4.0f);
  REQUIRE (rectangle2.get_height () == 7.0f);
  REQUIRE (rectangle2.get_area () == 28.0f);
  REQUIRE (rectangle2.get_color ().r == Approx (1.0f).epsilon(0.01));
}

//Aufgabe 2.9 

TEST_CASE ("Circumference_Rectangle", "[circum_rec]")
{
  Vec2 max_height1 {16.0f, 8.0f};
  Vec2 min_height1 {4.0f,1.0f};
  Color color2 {1.0f,1.0f,1.0f};
  Rectangle rectangle2 {max_height1, min_height1, color2};
  REQUIRE (rectangle2.get_width () == 12.0f);
  REQUIRE (rectangle2.get_height () == 7.0f);
  REQUIRE (rectangle2.get_area () == 84.0f);
  REQUIRE (rectangle2.get_color ().b == Approx (1.0f).epsilon(0.01));
  REQUIRE (rectangle2.get_circumference () == 38.0f);
}
TEST_CASE ("Circumference_Circle", "[circum_cir")
{
  Vec2 vector1 {8.0f,6.0f};
  Color color1 {0.0f, 1.0f, 1.0f};  
  Circle circle2 {10.0f, vector1, color1};  
  REQUIRE (circle2.get_radius() == 10.0f);
  REQUIRE (circle2.get_color ().g == 1.0f);
  REQUIRE (circle2.get_center ().x == 8.0f);
  REQUIRE (circle2.get_circumference () == Approx (62.83f).epsilon(0.01));
}

TEST_CASE ("Point-Inside-Circle", "[isinside-cir]")
{
  Vec2 point1 {150.0f, 200.0f};
  Vec2 point2 {50.0f, 50.0f};
  Circle circle1 {370.0f, {400.0f, 400.0f}, {0.0f,0.0f,0.0f}};
  REQUIRE (circle1.is_inside(point1)==true);
  REQUIRE (circle1.is_inside(point2)==false);
}

TEST_CASE ("Point-Inside-Rectangle", "[isinside-rec]")
{
  Vec2 point1 {50.0f, 80.0f};
  Vec2 point2 {780.0f, 6.0f};
  Rectangle rectangle1 {Vec2 (780.0f, 780.0f), Vec2(15.0f,15.0f), Color(0.5f, 0.4f, 1.0f)};
  REQUIRE (rectangle1.is_inside(point1)==true); 
  REQUIRE (rectangle1.is_inside(point2)==false);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
