#pragma once
#include "../main.h"

typedef struct s_fight_log {
  struct s_fight_log *next;
  char *text;
  SDL_Surface *surface;
} t_fight_log;

#define FIGHT_LOG_MAX_ENTRIES 8

void fight_log_add(struct s_fight*, char*);
void fight_log_clear(t_fight_log*);
void fight_log(t_game*);
