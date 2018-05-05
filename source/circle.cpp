#include "circle.hpp"
#include <iostream>

Circle::Circle ():
  radius{1.0},
  center{0.0,0.0},
  color{0,0,0}
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