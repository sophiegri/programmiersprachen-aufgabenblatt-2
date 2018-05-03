#ifndef VEC2_HPP
#define VEC2_HPP

// Die include guards im Header einer .hpp Datei (Klassen/Methodendefinition) sollen Mehrfacheinbindungen verhindert werden.
// ifdndef (Präprozessor-Makro) verhindert diese Mehrfacheinbindung, indem durch das erste Einbinden der Header-Datei 
// die nachfolgenden Definitionen des Headers übersprungen werden. 


struct Vec2
{

//Aufgabe 2.2

  Vec2 (); //Das ist der Standardkonstruktor, der bei 0 startet
  Vec2 (float _x, float _y); //Dieser Konstruktor ermoeglicht ein Objekt mit x und y zu bauen 

  float x;
  float y; 

 //Es ist nicht notwendig einen Destruktor anzulegen, da das Objekt nicht auf eine Datei oder aehnliches zugreift


 //Aufgabe 2.3

  Vec2& operator += (Vec2 const& v); //Das sind die Methoden des struct
  Vec2& operator -= (Vec2 const& v); //Das & (Referenz) zeigt an, dass wir etwas ändern was wir schon haben
  Vec2& operator *= (float s);
  Vec2& operator /= (float s);

};

//Aufgabe 2.4

Vec2 operator + (Vec2 const& u, Vec2 const& v); //freie Funktionen kommen außerhalb von der class/struct
Vec2 operator - (Vec2 const& u, Vec2 const& v); //wir erstellen einen neuen Vektor (Vec2)
Vec2 operator * (Vec2 const& v, float s); 
Vec2 operator / (Vec2 const& v, float s); 
Vec2 operator * (float s, Vec2 const& v); 

#endif



