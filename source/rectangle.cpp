#include "rectangle.hpp"
#include <iostream>


Rectangle::Rectangle ():
  max_height{1.0,1.0},
  min_height{0.0,0.0},
  color{0,0,0}
  {}

Rectangle::Rectangle (Vec2 const& _max_height, Vec2 const& _min_height, Color const& _color):
  max_height{_max_height},
  min_height{_min_height},
  color{_color}
  {}

float Rectangle::get_width () const
{
 float width = max_height.x - min_height.x;
 return width;
}

float Rectangle::get_height () const
{
  float height = max_height.y - min_height.y;
  return height;
}

float Rectangle::get_area() const
{  
  float area = get_width () * get_height ();
  return area;
}

Color Rectangle::get_color() const
{
  return color;
}