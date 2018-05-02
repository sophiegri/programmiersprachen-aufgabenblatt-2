#include "vec2.hpp"
#include <iostream>

Vec2::Vec2():
  x{0.0},
  y{0.0}
  {}
  
Vec2::Vec2 (float _x, float _y):
  x{_x},
  y{_y}
  {}


Vec2& Vec2::operator+=(Vec2 const& v)
{
  x+=v.x;
  y+=v.y;
  return *this; // Referenziert auf das ursprüngliche Objekt, welches zurückgegeben werden soll 
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
  x-=v.x;
  y-=v.y;
  return *this;
}

Vec2& Vec2::operator*=(float s) // S ist eine Skala
{
  x*=s; 
  y*=s;
  return *this;
}

Vec2& Vec2::operator/=(float s)
{
  if (s == 0) { // Hier wird ausgeschlossen durch 0 zu teilen 
      std::cout << "Ungueltige Werte, um eine Division durchzufuehren.\n";
      return *this;
    }

    else {
        x/=s;
        y/=s;
        return *this;
    } 
}