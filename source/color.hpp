#ifndef COLOR_HPP
#define COLOR_HPP
#include <algorithm>
#include <iostream>

struct Color
{

  float r; 
  float g; 
  float b; 

  Color (float _r, float _g, float _b)
  {

   if (_r<=1.0f && _r>=0.0f && _g<=1.0f && _g>=0.0f && _b<=1.0f && _b>=0.0f) {

    r = _r;
    g = _g;
    b = _b;

   }

   else {
    std::cout <<"Falsche Eingabe fuer einen Farbwert.Waehle zwischen 0-1\n";
    r = 0.0f;
    g = 0.0f;
    b = 0.0f;
   }
  };
  

  Color (float x){
    if(x>=0.0f && x<=1.0f)
    {
      r=x;
      g=x;
      b=x;     
    }

    else 
    {
      std::cout <<"Falsche Eingabe fuer einen Farbwert.Waehle zwischen 0-1\n";
      r = 0.0f;
      g = 0.0f;
      b = 0.0f;
    } 
  };

};

#endif 

