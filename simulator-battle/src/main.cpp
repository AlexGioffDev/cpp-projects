#include <iostream>
#include "Character.h"

using namespace std;

int main()
{

  Character warrior{"Razeft", "Warrior", 30, 20, 20, 15, 10};
  Character mage{"Ligua", "Mage", 30, 10, 10, 25, 20};

  warrior.printStatus();
  mage.printStatus();

  return 0;
}