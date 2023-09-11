#pragma once

typedef enum {
  menu_fight_attack,
  menu_fight_flee,
  menu_fight_num_values
} e_menu_fight_state;

void draw_menu_fight(t_game*);
