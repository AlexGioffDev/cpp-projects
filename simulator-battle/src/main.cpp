#include <iostream>
#include "Character.h"
#include "Mage.h"    // Assicurati di includere il file dell'header per Mage
#include "Warrior.h" // Assicurati di includere il file dell'header per Warrior
#include "Battle.h"
#include <random>
#include <memory>

using namespace std;

unique_ptr<Character> generate_character();
int generate_value(int min, int max = 0);

int main()
{
  unique_ptr<Character> warrior = make_unique<Mage>("Razeft");
  unique_ptr<Character> enemy = generate_character(); // Genera un nemico casuale

  Battle battle(*warrior, *enemy);
  battle.startBattle();

  while (battle.getStatus())
  {
    battle.battle();
  }

  return 0;
}

unique_ptr<Character> generate_character()
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

  // Creare un oggetto di tipo specifico in base al tipo generato
  if (types[indexType] == "Warrior")
  {
    return make_unique<Warrior>(name); // Creare un Warrior
  }
  else
  {
    return make_unique<Mage>(name); // Creare un Mage
  }
}

int generate_value(int min, int max)
{
  static random_device rd;
  static mt19937 gen(rd());
  uniform_int_distribution<> distrib(min, max);

  return distrib(gen);
}
