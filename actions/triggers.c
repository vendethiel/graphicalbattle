#include "../main.h"

trigger g_triggers[] = {
    trigger_mob_jirachi,
};

void trigger_mob_jirachi(t_game* game) {
  fight_start(game, monster_get(MOB_JIRACHI));
}
