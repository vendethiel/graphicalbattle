#pragma once

#include "main.h"

typedef struct s_tileset { char *tiles; } t_tileset;

typedef struct s_map {
  t_tileset *tilesets;
  int w;
  int h;
} t_map;

t_map *map_from_string(char *str, struct s_character *character);
void map_init(void);
void map_draw(struct s_game *);
