#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "Character.h"
#include <memory> // Include per std::unique_ptr

class Battle
{
private:
  int round;
  bool matchStarted;
  Character &player_a; // Riferimento al personaggio del giocatore
  Character &player_b; // Riferimento al nemico

public:
  // Costruttore che accetta riferimenti ai personaggi
  Battle(Character &playerA, Character &playerB);
  void battle();
  void startBattle();
  bool getStatus();
};

#endif
