#include "rectangle.hpp"
#include <iostream>
#include <cmath>

//Aufgabe 2.8 

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

//Aufgabe 2.9

float Rectangle::get_circumference () const
{
    float circumference = 2*get_height () + 2*get_width ();
    return circumference;
}

void Rectangle::draw (Window const& w) const 
{
    w.draw_line(min_height.x, min_height.y, max_height.x, min_height.y, 1.0f, 1.0f, 1.0f);
    w.draw_line(max_height.x, min_height.y, max_height.x, max_height.y, 1.0f, 1.0f, 1.0f);
    w.draw_line(max_height.x, max_height.y, min_height.x, max_height.y, 1.0f, 1.0f, 1.0f);
    w.draw_line(min_height.x, max_height.y, min_height.x, min_height.y, 1.0f, 1.0f, 1.0f);
}

void Rectangle::draw (Window const& w, Color const& color) const 
{
  w.draw_line(min_height.x, min_height.y, max_height.x, min_height.y, color.r, color.g, color.b);
  w.draw_line(max_height.x, min_height.y, max_height.x, max_height.y, color.r, color.g, color.b);
  w.draw_line(max_height.x, max_height.y, min_height.x, max_height.y, color.r, color.g, color.b);
  w.draw_line(min_height.x, max_height.y, min_height.x, min_height.y, color.r, color.g, color.b);
}