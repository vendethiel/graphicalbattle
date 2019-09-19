#include "../../main.h"

typedef struct s_monster_template {
  char* name;
  char sprite; // XXX shouldn't be needed, should use sprite long names
  int max_hp;
  int max_mp;
} t_monster_template;

static t_monster_template g_monster_templates[] = {
  {"jirachi", '?', 100, 25},
  {NULL, ' ', 0, 0}
};

static t_monster_template* monster_template_get(char* name) {
  int i;

  for (i = 0; g_monster_templates[i].name; ++i)
    if (!strcmp(name, g_monster_templates[i].name))
      return &g_monster_templates[i];
  printf("Can't find mob [%s]\n", name);
  exit(1);
}

static t_monster* monster_from_template(t_monster_template* tmpl) {
  t_monster* monster;

  monster = xmalloc(sizeof *monster);
  monster->tmpl = tmpl;
  monster->hp = tmpl->max_hp;
  monster->mp = tmpl->max_mp;
  return monster;
}

t_monster* monster_make(char* name) {
  return monster_from_template(monster_template_get(name));
}

t_sprite* monster_get_sprite(t_monster* monster) {
  return sprite_get(monster->tmpl->sprite);
}

void monster_play(t_game* game) {
  game->character->hp -= 10;
  printf("remaining char hp: %d\n", game->character->hp);
  if (game->character->hp < 1) {
    fight_end_to(game, GAMEOVER);
  } else {
    fight_change_state(game->fight, turn_monster_after);
  }
}

void monster_remove(t_game* game) {
  entity_remove(&game->entities, entity_monster, game->fight->monster);
}
