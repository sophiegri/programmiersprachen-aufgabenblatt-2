#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Circle 
{
    private: //Attribute sind immer privat
    float radius; 
    Vec2 center;
    Color color; 
    
    public: //Methoden und Konstruktor sind öffentlich
    Circle (); 
    Circle (float _radius, Vec2 const& _center, Color const& _color);
   

    Vec2 get_center() const;
    float get_radius() const; 
    Color get_color() const;  
    float get_circumference () const; 

//Aufgabe 2.11

    void draw (Window const& w) const;

    void draw (Window const& w, Color const& color) const; 

};

#endif