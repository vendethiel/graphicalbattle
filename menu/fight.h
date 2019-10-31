#pragma once

typedef enum {
  menu_fight_attack,
  menu_fight_flee,
} e_menu_fight_state;

void draw_menu_fight(t_game*);
