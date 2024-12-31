#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <iostream>
#include "Character.h"

class Warrior : public Character
{
public:
  Warrior(std::string name) : Character(name, "Warrior", 60, 50, 15, 50, 25, 25) {}

  void attackTarget(Character &target) override
  {
    const int minDamage{10};
    int calculateDamage{0};

    float random_multiplier = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1.2f - 0.8f)));
    float critical_multiplier = (rand() % 100) < 10 ? 1.5f : 1.0f;

    calculateDamage = static_cast<int>((this->attack - target.get_spDefense()) * random_multiplier * critical_multiplier);

    if (calculateDamage < minDamage)
    {
      calculateDamage = minDamage;
    }

    target.takeDamage(calculateDamage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " causing " << calculateDamage << " points of damage." << std::endl;
  }
};

#endif