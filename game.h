#pragma once

typedef enum { GAME_MENU, CLASS_MENU, MAP, MAP_MENU, FIGHT, GAMEOVER } e_state;

typedef struct s_game {
  SDL_Window* window;
  SDL_Surface* screen;
  t_map* map;
  t_character* character;
  struct s_fight* fight;
  e_state state;
  t_class *classes;
} t_game;

typedef void (*tick_fn)(t_game*);
typedef struct {
  e_state state;
  tick_fn fn;
} t_tick;

extern t_tick g_tick_fns[];

t_game* game_init(SDL_Window*);
void game_tick(t_game*);
void game_quit(t_game*);
