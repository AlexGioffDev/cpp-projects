#include "raylib.h"
#include "raymath.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <vector>

void drawMap(std::vector<Rectangle> &block);
void checkCollisionPlayer(Player &player, std::vector<Rectangle> &map);
void createMap(std::vector<std::string> &map, std::vector<Rectangle> &block);

int main(void)
{
  InitWindow(800, 800, "Raylib exampe");
  SetTargetFPS(60);

  std::vector<std::string> map = {
      "1111111111111111111111111",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1000000000000000000000001",
      "1111111111111111111111111",
  };

  std::vector<Rectangle> blocks;
  createMap(map, blocks);

  Player player = Player(Rectangle{400 - 80, 400 - 80, 80, 80}, RED, {0, 0});

  while (!WindowShouldClose())
  {

    // Check Inputs
    player.move();
    checkCollisionPlayer(player, blocks);

    BeginDrawing();
    ClearBackground(BLACK);
    drawMap(blocks);
    player.draw();
    EndDrawing();
  }

  return 0;
}

void createMap(std::vector<std::string> &map, std::vector<Rectangle> &block)
{
  for (int row = 0; row < map.size(); row++)
  {
    for (int j = 0; j < map[row].size(); j++)
    {
      if (map[row][j] == '1')
      {
        // DrawRectangleV({(float)j * 32,
        //                 (float)row * 32},
        //                {32, 32}, GRAY);
        Rectangle rec = Rectangle{float(j) * 32, float(row) * 32, 32, 32};
        block.push_back(rec);
      }
    }
  }
}

void drawMap(std::vector<Rectangle> &block)
{
  for (Rectangle rec : block)
  {
    DrawRectangleRec(rec, GRAY);
  }
}

void checkCollisionPlayer(Player &player, std::vector<Rectangle> &map)
{
  Vector2 initialPosition = {player.getRectangle().x, player.getRectangle().y};

  // Movimento e correzione su X
  player.changePosition({initialPosition.x + player.getDirection().x, initialPosition.y});

  for (Rectangle rec : map)
  {
    if (CheckCollisionRecs(rec, player.getRectangle()))
    {
      // Correggi la posizione su X
      if (player.getDirection().x > 0) // Andando a destra
      {
        player.changePosition({rec.x - player.getRectangle().width, initialPosition.y});
      }
      else if (player.getDirection().x < 0) // Andando a sinistra
      {
        player.changePosition({rec.x + rec.width, initialPosition.y});
      }
    }
  }

  // Aggiorna la posizione iniziale dopo la correzione su X
  initialPosition = {player.getRectangle().x, player.getRectangle().y};

  // Movimento e correzione su Y
  player.changePosition({initialPosition.x, initialPosition.y + player.getDirection().y});

  for (Rectangle rec : map)
  {
    if (CheckCollisionRecs(rec, player.getRectangle()))
    {
      // Correggi la posizione su Y
      if (player.getDirection().y > 0) // Andando verso il basso
      {
        player.changePosition({player.getRectangle().x, rec.y - player.getRectangle().height});
      }
      else if (player.getDirection().y < 0) // Andando verso l'alto
      {
        player.changePosition({player.getRectangle().x, rec.y + rec.height});
      }
    }
  }
}
