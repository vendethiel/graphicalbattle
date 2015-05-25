#include "../../main.h"

void event_keydown_gamemenu(SDL_Event event, t_game* game) {
  if (event.key.keysym.sym == SDLK_RETURN)
    game->state = CLASS_MENU;
}

void event_keydown_classmenu(SDL_Event event, t_game* game) {
  if (event.key.keysym.sym == SDLK_RETURN)
    game->state = MAP;
}

void event_keydown_map(SDL_Event event, t_game* game) {
  printf("keydown map\n");
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
  if (event.key.keysym.sym == SDLK_RETURN) {
    game->fight->monster->hp -= 50;
    if (game->fight->monster->hp < 1)
      game->state = MAP;
  }
}

void event_keydown_void(SDL_Event event, t_game* game) {
  if (event.key.keysym.sym == SDLK_LEFT && game) {
  }
}
