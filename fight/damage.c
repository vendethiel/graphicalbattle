#include "../main.h"

int fight_damage_player(t_character* character, t_monster* monster) {
  if (!character || !monster)
    return 0;
  return 20;
}

int fight_damage_monster(t_monster* monster, t_character* character) {
  if (!character || !monster)
    return 0;
  return 10;
}