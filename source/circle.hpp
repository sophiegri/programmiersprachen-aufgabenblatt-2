#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"


class Circle 
{
    private: //Attribute sind immer privat
    float radius; 
    Vec2 center; 
    string name; 
    Color color; 
    
    public: //Methoden und Konstruktor sind öffentlich
    Circle (); 
    Circle (float _radius, Vec2 const& _center, Color const& _color);
   

    Vec2 get_center() const;
    float get_radius() const; 
    Color get_color() const;    

};

#endif