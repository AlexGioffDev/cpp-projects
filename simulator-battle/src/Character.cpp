#include "Character.h"

#include <iostream>

std::string Character::get_name() const { return name; }
std::string Character::get_type() const { return type; }
int Character::get_health() const { return health; }

void Character::set_attack(int amount)
{
  if (amount < 5)
  {
    attack = 5;
    return;
  }
  attack = amount;
}

void Character::set_speed(int amount)
{
  if (amount < 5)
  {
    speed = 5;
    return;
  }
  speed = amount;
}

void Character::set_defense(int amount)
{
  if (amount < 5)
  {
    defense = 5;
    return;
  }

  defense = amount;
}

void Character::set_health(int amount)
{
  if (amount < 0)
    return;
  health = amount;
}

void Character::set_spAttack(int amount)
{
  if (amount < 5)
  {
    spAttack = 5;
    return;
  }
  else
  {
    spAttack = amount;
  }
}

void Character::set_spDefense(int amount)
{
  if (amount < 5)
  {
    spDefense = 5;
    return;
  }

  spDefense = amount;
}

Character::Character(std::string name, std::string type, int health, int attack, int speed, int defense, int spAttack, int spDefense) : name{name}, type{type}, health{health}, attack{attack}, speed{speed}, defense{defense}, spAttack{spAttack}, spDefense{spDefense}
{
  if (type == "Warrior")
  {
    set_health(this->health + 20);
    set_attack(this->attack + 10);
    set_speed(this->speed - 8);
    set_defense(this->defense + 10);
    set_spAttack(this->spAttack - 10);
    set_spDefense(this->spDefense - 10);
  }

  if (type == "Mage")
  {
    set_health(this->health);
    set_attack(this->attack - 10);
    set_speed(this->speed + 8);
    set_defense(this->defense - 10);
    set_spAttack(this->spAttack + 15);
    set_spDefense(this->spDefense + 15);
  }
}

void Character::attackTarget(Character &target, std::string type)
{
  int minDamage{5};
  int calculateDamage{0};

  if (type == "attack")
  {
    calculateDamage = this->attack - target.defense;
  }
  else if (type == "sp attack")
  {
    calculateDamage = this->spAttack - target.spDefense;
  }

  if (calculateDamage < minDamage)
    calculateDamage = minDamage;

  target.takeDamage(calculateDamage);

  std::cout << this->get_name() << " attack " << target.get_name() << " for this damage: " << calculateDamage << std::endl;
}

void Character::takeDamage(int amount)
{
  this->health -= amount;
}

bool Character::isAlive() const
{
  return health > 0;
}

void Character::heal(int amount)
{
  std::cout << "Working on..." << std::endl;
}

void Character::printStatus() const
{
  std::cout << "Stats Character: " << name << " (" << type << ")" << std::endl;
  std::cout << "\tHealth: \t\t" << health << std::endl;
  std::cout << "\tAttack: \t\t" << attack << std::endl;
  std::cout << "\tSpeed: \t\t\t" << speed << std::endl;
  std::cout << "\tDefense: \t\t" << defense << std::endl;
  std::cout << "\tSpAttack: \t\t" << spAttack << std::endl;
  std::cout << "\tSpDefense: \t\t" << spDefense << std::endl;
}

int Character::get_attack() const
{
  return this->attack;
}

int Character::get_speed() const
{
  return this->speed;
}