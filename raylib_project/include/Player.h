#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "raylib.h"
#include "raymath.h"

class Player
{

private:
  Rectangle rec = Rectangle();
  Color color = Color(RED);
  Vector2 direction = Vector2();

public:
  Player(Rectangle rec, Color color = Color(RED), Vector2 dir = Vector2{0, 0}) : rec(rec), color(color), direction(dir) {};
  void move();
  void draw();
  Rectangle getRectangle();
  Vector2 getDirection();
  void changePosition(Vector2 value);
};

#endif