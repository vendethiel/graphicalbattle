#pragma once
#include "log.h"

#define FIGHT_WAIT_TICKS 60
typedef enum {
  turn_player, turn_player_after, turn_monster, turn_monster_after
} e_fight_state;
// turn player -> turn player after... -> turn monster -> turn monster after...

typedef struct s_fight {
  t_monster *monster;
  e_fight_state state;
  int ticker;
  e_menu_fight_state menu;
  t_fight_log *log;
} t_fight;

void fight_start(t_game*, t_monster*);
void fight_player_act(t_game*);
void fight_change_state(t_fight*, e_fight_state);
void fight_end_to(t_game*, e_state);
void fight_bg(t_game*);
