#include "Battle.h"
#include <iostream>

Battle::Battle(Character &playerA, Character &playerB)
    : player_a(playerA), player_b(playerB), round(0), matchStarted(false) {}

void Battle::startBattle()
{
  this->matchStarted = true;
}

bool Battle::getStatus()
{
  return this->matchStarted;
}

void Battle::battle()
{
  while (player_a.isAlive() && player_b.isAlive())
  {
    round++;
    std::cout << "Round: " << this->round << std::endl;
    std::cout << "Player A HP: " << player_a.get_health() << std::endl;
    std::cout << "Player B HP: " << player_b.get_health() << std::endl;

    // Determina chi attacca per primo basato sulla velocità
    if (player_a.get_speed() >= player_b.get_speed())
    {
      player_a.attackTarget(player_b); // Player A attacca Player B
      if (!player_b.isAlive())
      {
        std::cout << player_a.get_name() << " Wins!" << std::endl;
        this->matchStarted = false;
        break;
      }
      player_b.attackTarget(player_a); // Player B attacca Player A
      if (!player_a.isAlive())
      {
        std::cout << player_b.get_name() << " Wins!" << std::endl;
        this->matchStarted = false;
        break;
      }
    }
    else
    {
      player_b.attackTarget(player_a); // Player B attacca Player A
      if (!player_a.isAlive())
      {
        std::cout << player_b.get_name() << " Wins!" << std::endl;
        this->matchStarted = false;
        break;
      }
      player_a.attackTarget(player_b); // Player A attacca Player B
      if (!player_b.isAlive())
      {
        std::cout << player_a.get_name() << " Wins!" << std::endl;
        this->matchStarted = false;
        break;
      }
    }
  }
}
