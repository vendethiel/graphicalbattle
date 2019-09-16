#pragma once

#define FIGHT_WAIT_TICKS 60
typedef enum {
  turn_player, turn_player_after, turn_monster, turn_monster_after
} e_fight_state;
// turn player -> turn player after... -> turn monster -> turn monster after...

typedef struct s_fight {
  t_monster* monster;
  e_fight_state state;
  int ticker;
} t_fight;

void fight_start(t_game*, t_monster*);
void fight_player_attack(t_game*);
void fight_change_state(t_fight*, e_fight_state);
void fight_end_to(t_game*, e_state);
void fight_bg();
void draw_in_battle(t_game*);
