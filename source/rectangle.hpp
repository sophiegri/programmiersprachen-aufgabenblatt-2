#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Rectangle
{
    private:
    Vec2 max_height; //top right, x2, y2
    Vec2 min_height; //bottom left, x1, y1
    Color color; 

    
    public:
    Rectangle (); 
    Rectangle (Vec2 const& _max_height, Vec2 const& _min_height, Color const& _color);

    Color get_color() const;
    float get_width () const;
    float get_height () const; 
    float get_area () const;  
    float get_circumference () const; 

//Aufgabe 2.10

    void draw (Window const& w) const;

};

#endif