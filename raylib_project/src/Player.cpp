#include "Player.h"

void Player::move()
{
  float DT = GetFrameTime();
  direction.x = int(IsKeyDown(KEY_RIGHT)) - int(IsKeyDown(KEY_LEFT));
  direction.y = int(IsKeyDown(KEY_DOWN)) - int(IsKeyDown(KEY_UP));
  direction = Vector2Normalize(direction);

  rec.x += direction.x * 300 * DT;
  rec.y += direction.y * 300 * DT;
}

void Player::draw()
{
  DrawRectangleRec(rec, color);
}

Rectangle Player::getRectangle()
{
  return rec;
}

Vector2 Player::getDirection()
{
  return direction;
}

void Player::changePosition(Vector2 value)
{
  rec.x = value.x;
  rec.y = value.y;
}