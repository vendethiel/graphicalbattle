#pragma once

#include "main.h"

typedef enum {
  entity_monster
} e_entity_type;

typedef struct s_entity {
  struct s_entity *next;
  e_entity_type type;
  int x, y;
  union {
    struct s_monster* monster;
  };
} t_entity;

t_entity* entities_from_string(struct s_game*, char*);
void entity_remove(t_entity**, e_entity_type, void*);
t_entity* entity_at(t_entity*, int x, int y);
t_sprite* entity_get_sprite(t_entity*);
void entity_trigger(struct s_game*, t_entity*);
