#pragma once
struct s_monster_template;

typedef struct s_monster {
  struct s_monster_template* tmpl;
  int hp;
  int mp;
  /* script ?? */
} t_monster;

t_monster* monster_make(char*);
t_sprite* monster_get_sprite(t_monster* monster);
char const* monster_name(t_monster*);
void monster_play(t_game*);
void monster_remove(t_game*);
