#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <string>

class Character
{
protected:
  std::string name;
  std::string type;
  int health;
  int attack;
  int speed;
  int defense;
  int spAttack;
  int spDefense;

public:
  Character(std::string name, std::string type, int health, int attack, int speed, int defense, int spAttack, int spDefense);
  virtual ~Character() {};
  virtual void attackTarget(Character &target);
  void takeDamage(int damage);
  bool isAlive() const;
  void heal(int amount);
  void printStatus() const;

  // Getters
  std::string get_name() const;
  std::string get_type() const;
  int get_speed() const;
  int get_health() const;
  int get_attack() const;
  int get_defense() const;
  int get_spAttack() const;
  int get_spDefense() const;

  // Setters
  void set_speed(int amount);
  void set_health(int amount);
  void set_attack(int amount);
  void set_defense(int amount);
  void set_spAttack(int amount);
  void set_spDefense(int amount);
};

#endif