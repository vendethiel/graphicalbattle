#include "../../main.h"
#define NUM_MONSTERS 1

t_monster g_monsters[] = {
    {MOB_JIRACHI, "Jirachi", 100, 25},
};

t_monster *monster_get(e_mob id) {
  int i;

  for (i = 0; i < NUM_MONSTERS; ++i)
    if (g_monsters[i].id == id)
      return (&g_monsters[i]);
  printf("Can't find mob %i\n", id);
  exit(1);
}

void monster_play(t_game *game) { game->character->hp -= 10; }