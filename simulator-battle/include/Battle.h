#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "Character.h"

class Battle
{

private:
  int round;
  bool matchStarted;
  Character player_a;
  Character player_b;

public:
  Battle(Character &playerA, Character &playerB);
  void battle();
  void startBattle();
  bool getStatus();
};

#endif