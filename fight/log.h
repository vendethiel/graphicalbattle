#pragma once

typedef struct s_fight_log {
  struct s_fight_log *next;
  const char *text;
} t_fight_log;

void fight_log_add(t_fight*, const char*);
