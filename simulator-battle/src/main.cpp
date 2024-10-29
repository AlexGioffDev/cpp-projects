#include <iostream>
#include "Character.h"
#include "Battle.h"
#include <random>

using namespace std;

Character *generate_character();

int generate_value(int min, int max = 0);

int main()
{

  Character warrior{"Razeft", "Warrior", 50, 30, 35, 30, 30, 30};
  Character *enemy = generate_character();

  Battle battle(warrior, *enemy);
  battle.startBattle();
  while (battle.getStatus())
  {
    battle.battle();
  }

  delete enemy;

  return 0;
}

Character *generate_character()
{

  string types[2]{"Warrior", "Mage"};
  string name = "Enemy";

  int indexType = generate_value(0, 1);
  int health = generate_value(30, 40);
  int attack = generate_value(25, 30);
  int speed = generate_value(15, 25);
  int defense = generate_value(15, 25);
  int spAttack = generate_value(20, 30);
  int spDefense = generate_value(20, 30);

  return new Character{name, types[indexType], health, attack, speed, defense, spAttack, spDefense};
}

int generate_value(int min, int max)
{
  static random_device rd;
  static mt19937 gen(rd());
  uniform_int_distribution<> distrib(min, max);

  return distrib(gen);
}