#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"


class Rectangle
{
    private:
    Vec2 max_height;
    Vec2 min_height;  
    Color color; 

    
    public:
    Rectangle (); 
    Rectangle (Vec2 const& _max_height, Vec2 const& _min_height, Color const& _color);

    Color get_color() const;
    float get_width () const;
    float get_height () const; 
    float get_area () const;   
};

#endif