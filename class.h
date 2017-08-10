#pragma once

typedef struct s_class_menu {
  char* img;
  int x;
  int y;
  SDL_Surface* surface;
} t_class_menu;

typedef struct s_class {
  char* name;
  int hp_pool;
  int mp_pool;
  t_class_menu menu;
} t_class;

t_class* class_init(void);
void class_quit(void);
