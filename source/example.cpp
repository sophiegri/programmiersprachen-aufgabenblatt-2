#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"


int main(int argc, char* argv[])
{ 

  Circle circle_1 {370.0f, Vec2(400.0f,400.0f), Color (0.0f,0.6f,0.0f)};
  Circle circle_2 {250.0f, Vec2(480.0f,420.0f), Color(0.2f,0.3f,0.4f)};
  Circle circle_3 {120.0f, Vec2(300.0f,180.0f), Color(0.2f,0.8f,1.0f)};
  
  
  Rectangle rectangle_1 {Vec2 (215.0f, 450.0f), Vec2(120.0f, 550.0f), Color(0.2f, 0.7f, 1.0f)};
  Rectangle rectangle_2 {Vec2 (780.0f, 15.0f), Vec2(15.0f,780.0f), Color(0.5f, 0.4f, 1.0f)};
  Rectangle rectangle_3 {}; //Jetzt wird durch color const die Farbe auf weiß gesetzt 

  Color color1 {0.2f,0.3f,0.8f}; //Es wird eine neue Farbe gesetzt 

 
 
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    circle_1.draw(win);
    circle_1.draw(win, color1); //die neue Farbe wird aufgerufen
    circle_2.draw(win);
    circle_2.draw(win, {0.6f, 0.0f,0.8f}); //es wird direkt eine neue Farbe gesetzt
    circle_3.draw(win);
    rectangle_1.draw(win);
    rectangle_2.draw(win);
    rectangle_3.draw(win); //es wird die Methode ohne color aufgerufen, deswegen wird dieses Rechteck weiß gezeichnet
    

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);


    // mouse_position gibt ein double pair -> std::get<0> um den ersten wert zu bekommen
    if (circle_1.is_inside({(float) std::get<0> (win.mouse_position() ),(float) std::get<1> (win.mouse_position() )}) )
    {
      circle_1.draw (win, {0.0f, 0.0f, 1.0f});
    } 
    else 
    {
      circle_1.draw (win);
    }


     if (circle_2.is_inside( {(float) std::get<0> (win.mouse_position() ), (float) std::get<1> (win.mouse_position() )} ))
    {
      circle_2.draw (win, {0.0f, 0.0f, 1.0f});
    } 
    else 
    {
      circle_2.draw (win);
    }



     if (circle_3.is_inside( {(float) std::get<0> (win.mouse_position() ), (float) std::get<1> (win.mouse_position() )} ))
    {
      circle_3.draw (win, {0.0f, 0.0f, 1.0f});
    } 
    else 
    {
      circle_3.draw (win);
    } 
  


    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

    win.update();

  }

  return 0;
}
