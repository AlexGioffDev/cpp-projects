#include "Battle.h"
#include <iostream>
#include <random>

Battle::Battle(Character &playerA, Character &playerB) : player_a{playerA}, player_b{playerB}
{
  this->round = 0;
  this->matchStarted = false;
}

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
  while (player_a.isAlive() || player_b.isAlive())
  {
    round++;
    std::cout << "Round: " << this->round << std::endl;
    std::cout << "Player A HP: " << player_a.get_health() << std::endl;
    std::cout << "Player B HP: " << player_b.get_health() << std::endl;
    if (player_a.get_speed() > player_b.get_speed())
    {

      // Type of attack
      if (player_a.get_type() == "Warrior")
        player_a.attackTarget(player_b, "attack");
      else
        player_a.attackTarget(player_b, "sp attack");

      // Check if player_b is alive
      if (!player_b.isAlive())
      {
        std::cout << player_a.get_name() << " Win!" << std::endl;
        this->matchStarted = false;
        break;
      }

      // Player B Attack
      if (player_b.get_type() == "Warrior")
        player_b.attackTarget(player_a, "attack");
      else
        player_b.attackTarget(player_a, "sp attack");

      if (!player_a.isAlive())
      {
        std::cout << player_b.get_name() << " Win!" << std::endl;
        this->matchStarted = false;

        break;
      }
    }
    else if (player_a.get_speed() < player_b.get_speed())
    {
      // Type of attack
      if (player_b.get_type() == "Warrior")
        player_b.attackTarget(player_a, "attack");
      else
        player_b.attackTarget(player_a, "sp attack");

      // Check if player_b is alive
      if (!player_a.isAlive())
      {
        std::cout << player_b.get_name() << " Win!" << std::endl;
        this->matchStarted = false;

        break;
      }

      // Player B Attack
      if (player_a.get_type() == "Warrior")
        player_a.attackTarget(player_b, "attack");
      else
        player_a.attackTarget(player_b, "sp attack");

      if (!player_b.isAlive())
      {
        std::cout << player_a.get_name() << " Win!" << std::endl;
        this->matchStarted = false;

        break;
      }
    }
    else
    {
      static std::random_device rd;
      static std::mt19937 gen(rd());
      std::uniform_int_distribution<> distrib(1, 2);

      int value = distrib(gen);

      if (value == 1)
      {
        // Type of attack
        if (player_a.get_type() == "Warrior")
          player_a.attackTarget(player_b, "attack");
        else
          player_a.attackTarget(player_b, "sp attack");

        // Check if player_b is alive
        if (!player_b.isAlive())
        {
          std::cout << player_a.get_name() << " Win!" << std::endl;
          this->matchStarted = false;

          break;
        }

        // Player B Attack
        if (player_b.get_type() == "Warrior")
          player_b.attackTarget(player_a, "attack");
        else
          player_b.attackTarget(player_a, "sp attack");

        if (!player_a.isAlive())
        {
          std::cout << player_b.get_name() << " Win!" << std::endl;
          this->matchStarted = false;

          break;
        }
      }
      else
      {
        if (player_b.get_type() == "Warrior")
          player_b.attackTarget(player_a, "attack");
        else
          player_b.attackTarget(player_a, "sp attack");

        // Check if player_b is alive
        if (!player_a.isAlive())
        {
          std::cout << player_b.get_name() << " Win!" << std::endl;
          this->matchStarted = false;

          break;
        }

        // Player B Attack
        if (player_a.get_type() == "Warrior")
          player_a.attackTarget(player_b, "attack");
        else
          player_a.attackTarget(player_b, "sp attack");

        if (!player_b.isAlive())
        {
          std::cout << player_a.get_name() << " Win!" << std::endl;
          this->matchStarted = false;

          break;
        }
      }
    }
  }
}