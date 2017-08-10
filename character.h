#pragma once

#include "main.h"

typedef struct s_character {
  int x;
  int y;
  int vx;
  int vy;
  int classid;
  struct s_sprite sprite;
  int hp;
} t_character;

t_character* character_init(void);
void character_move(struct s_game*);
t_class* character_class(struct s_game* game);
