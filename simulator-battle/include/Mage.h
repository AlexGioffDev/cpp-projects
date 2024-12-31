#ifndef __MAGE_H__
#define __MAGE_H__
#include <iostream>

#include "Character.h"

class Mage : public Character
{
public:
  Mage(std::string name) : Character(name, "Mage", 40, 25, 40, 25, 50, 50)
  {
  }

  void attackTarget(Character &target) override
  {
    const int minDamage{10};
    int calculateDamage{0};

    float random_multiplier = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1.2f - 0.8f)));
    float critical_multiplier = (rand() % 100) < 10 ? 1.5f : 1.0f;

    calculateDamage = static_cast<int>((this->spAttack - target.get_spDefense()) * random_multiplier * critical_multiplier);

    if (calculateDamage < minDamage)
    {
      calculateDamage = minDamage;
    }

    target.takeDamage(calculateDamage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " causing " << calculateDamage << " points of damage." << std::endl;
  }
};

#endif