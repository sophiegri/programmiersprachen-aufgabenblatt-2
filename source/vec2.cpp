#include "vec2.hpp"
#include <iostream>

//Aufgabe 2.2

Vec2::Vec2():
  x{0.0},
  y{0.0}
  {}
  
Vec2::Vec2 (float _x, float _y):
  x{_x},
  y{_y}
  {}

//Aufgabe 2.3

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
//Aufgabe 2.4

Vec2 operator + (Vec2 const& u, Vec2 const& v)
{   
  Vec2 result {u}; //in einem neuen Objekt result werden die Eigenschaften von u übernommen
  result += v; //das Objekt result wird mit v addiert und das Ergebnis wird in result gespeichert
  return result; //result wird zurückgegeben
}

Vec2 operator - (Vec2 const& u, Vec2 const& v)
{
  Vec2 result {u}; //geschweifte Klammern, um den Konstruktor aufzurufen, sonst koennte auch eine Methode gemeint sein
  result -= v; 
  return result;
}

Vec2 operator * (Vec2 const& v, float s)
{
  Vec2 result {v}; 
  result *= s;
  return result;
}

Vec2 operator / (Vec2 const& v, float s)
{
  if (s == 0) {
    return v;
  }
  else {
    Vec2 result {v}; 
    result /= s;
    return result;
  }
 } 


Vec2 operator * (float s, Vec2 const& v)
{
  return v*s; //hier kann ich die Methode von oben aufrufen, aber v kommt zuerst weil es oben zuerst war
}

