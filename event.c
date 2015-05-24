#include "main.h"

t_event g_events[] = {{GAME_MENU, event_keydown_gamemenu},
                      {CLASS_MENU, event_keydown_classmenu},
                      {MAP, event_keydown_map},
                      {MAP_MENU, event_keydown_void},
                      {FIGHT, event_keydown_fight}};

void event_keydown(SDL_Event event, t_game *game) {
  int i;

  for (i = 0; i < NUM_STATES; ++i)
    if (g_events[i].state == game->state) {
      g_events[i].fn(event, game);
      return;
    }
  err("keydown : game is in corrupted state");
}
