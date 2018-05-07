#include "circle.hpp"
#include <iostream>
#include <cmath>

//Aufgabe 2.8 

Circle::Circle ():
  radius{1.0f},
  center{0.0f,0.0f},
  color{0.0f,0.0f,0.0f}
  {}

Circle::Circle (float _radius, Vec2 const& _center, Color const& _color):
  radius{_radius},
  center{_center},
  color{_color}
  {} 


Vec2 Circle::get_center() const
{
  return center; 
}

float Circle::get_radius() const
{
  return radius;
}

Color Circle::get_color() const
{
  return color;
}

//Aufgabe 2.9 

float Circle::get_circumference () const
{
  float circumference = 2*(M_PI)*get_radius();
  return circumference;
}

void Circle::draw (Window const& w) const
{
  for (int i=0; i<2000; i++) {

      float x1{center.x + radius * std::sin(w.get_time()+i)};
      float y1{center.y + radius * std::cos(w.get_time()+i)};
      w.draw_point(x1, y1, color.r, color.g, color.b);

}
}

void Circle::draw (Window const& w, Color const& color) const 
{ 
  for (int i=0; i<2000; i++) {

    float x1{center.x + radius * std::sin(w.get_time()+i)};
    float y1{center.y + radius * std::cos(w.get_time()+i)};
    w.draw_point(x1, y1, color.r, color.g, color.b);
}
}
//Aufgabe 2.13

bool Circle::is_inside (Vec2 const& point) const
{
  if (pow ((center.x - point.x) , 2) + pow ((center.y-point.y) , 2) <= pow (radius ,2))
  {
    return true;
  }
  else {
    return false;
  }
}


