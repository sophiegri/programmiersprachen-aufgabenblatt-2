#ifndef VEC2_HPP
#define VEC2_HPP


struct Vec2
{

  Vec2 (); //Das ist der Standardkonstruktor, der bei 0 startet
  Vec2 (float _x, float _y); //Dieser Konstruktor ermoeglicht ein Objekt mit x und y zu bauen 


 float x;
 float y; 

};

#endif

//Hier wurde nur deklariert und noch nichts definiert  
//Es ist nicht notwendig einen Destruktor anzulegen, da das Objekt nicht auf eine Datei oder aehnliches zugreift

