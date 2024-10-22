#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <string>

class Character
{
private:
  std::string name;
  std::string type;
  int health;
  int attack;
  int defense;
  int spAttack;
  int spDefense;

public:
  Character(std::string name, std::string type, int health, int attack, int defense, int spAttack, int spDefense);
  void attackTarget(Character &enemy);
  void takeDamage(int damage);
  bool isAlive() const;
  void heal(int amount);
  void printStatus() const;

  // Getters
  std::string get_name();
  std::string get_type();
  int get_health();
  int get_attack();
  int get_spAttack();
  int get_spDefense();

  // Setters
  void set_health(int amount);
  void set_attack(int amount);
  void set_defense(int amount);
  void set_spAttack(int amount);
  void set_spDefense(int amount);
};

#endif