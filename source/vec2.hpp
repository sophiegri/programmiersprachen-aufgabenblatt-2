#ifndef VEC2_HPP
#define VEC2_HPP

// Die include guards im Header einer .hpp Datei (Klassen/Methodendefinition) sollen Mehrfacheinbindungen verhindert werden.
// ifdndef (Präprozessor-Makro) verhindert diese Mehrfacheinbindung, indem durch das erste Einbinden der Header-Datei 
// die nachfolgenden Definitionen des Headers übersprungen werden. 


struct Vec2
{

  Vec2 (); //Das ist der Standardkonstruktor, der bei 0 startet
  Vec2 (float _x, float _y); //Dieser Konstruktor ermoeglicht ein Objekt mit x und y zu bauen 


 float x;
 float y; 

  Vec2& operator += (Vec2 const& v);
  Vec2& operator -= (Vec2 const& v);
  Vec2& operator *= (float s);
  Vec2& operator /= (float s);

};

#endif

//Es ist nicht notwendig einen Destruktor anzulegen, da das Objekt nicht auf eine Datei oder aehnliches zugreift

