#include "../../main.h"

void event_keydown_gamemenu(SDL_Event event, t_game* game) {
  if (event.key.keysym.sym == SDLK_RETURN)
    game->state = CLASS_MENU;
}

void event_keydown_classmenu(SDL_Event event, t_game* game) {
  t_character* c = game->character;
  if (event.key.keysym.sym == SDLK_UP)
    c->classid = c->classid ? c->classid - 1 : 0;
  if (event.key.keysym.sym == SDLK_DOWN)
    c->classid = game->classes[c->classid + 1].name ? c->classid + 1 : c->classid;
  if (event.key.keysym.sym == SDLK_RETURN) {
    printf("Picked class: %s.\n", game->classes[c->classid].name);
    game->state = MAP;
  }
}

void event_keydown_map(SDL_Event event, t_game* game) {
  if (event.key.keysym.sym == SDLK_LEFT)
    game->character->vx = -1;
  else if (event.key.keysym.sym == SDLK_RIGHT)
    game->character->vx = 1;

  if (event.key.keysym.sym == SDLK_UP)
    game->character->vy = -1;
  else if (event.key.keysym.sym == SDLK_DOWN)
    game->character->vy = 1;
}

void event_keydown_fight(SDL_Event event, t_game* game) {
  if (!game->fight || game->fight->state != turn_player) {
    return;
  }

  // TODO left/right to pick an action
  switch (event.key.keysym.sym) {
  case SDLK_RETURN:
    fight_player_act(game);
    break;
  case SDLK_UP:
    if (game->fight->menu <= 0)
      return;
    game->fight->menu--;
    break;
  case SDLK_DOWN:
    if (game->fight->menu >= menu_fight_num_values - 1)
      return;
    game->fight->menu++;
    break;
  }
}

void event_keydown_void(SDL_Event event, t_game* game) {
  if (event.key.keysym.sym == SDLK_LEFT && game) {
  }
}
