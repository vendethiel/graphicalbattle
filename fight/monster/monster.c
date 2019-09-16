#include "../../main.h"

t_monster g_monsters[] = {
  {MOB_JIRACHI, "Jirachi", 100, 25},
  {0, NULL, 0, 0}
};

t_monster* monster_get(e_mob id) {
  int i;

  for (i = 0; g_monsters[i].name; ++i)
    if (g_monsters[i].id == id)
      return &g_monsters[i];
  printf("Can't find mob %i\n", id);
  exit(1);
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
  /* replace the mob tile with an empty one */
  /* TODO don't use the same layer for mobs */
  game->map->tilesets[game->character->y].tiles[game->character->x] = ' ';
}
