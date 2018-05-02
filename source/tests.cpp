#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

//Aufgabe 2.2


TEST_CASE ("Vector" ,"[vec]")
{
  Vec2 vector1 {}; //Hier wird ein Objekt mit dem Standardkonstruktor angelegt 
  Vec2 vector2 {2.4,1.5}; //Hier wird ein Objekt mit dem Konstruktor erstellt
  REQUIRE (Vec2 (2.4, 1.5).x == Approx(2.4));
  REQUIRE (vector2.x == Approx (2.4));
  REQUIRE (Vec2 (-9.7, 9.0).y == Approx(9.0));
  REQUIRE (vector1.y == Approx (0.0));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

