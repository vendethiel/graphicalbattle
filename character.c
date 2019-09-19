#include "main.h"

t_character* character_init(void) {
  t_character* character;

  character = xcalloc(1, sizeof(t_character));
  character->sprite = sprite_get('+');
  character->hp = 100;
  return character;
}

t_class* character_class(t_game* game) {
  return game->classes + game->character->classid;
}

void character_move(t_game* game) {
  int newx;
  int newy;
  t_entity* entity;

  newx = game->character->x + game->character->vx;
  newy = game->character->y + game->character->vy;
  game->character->vx = game->character->vy = 0; // TODO keyup
  if ((entity = entity_at(game->entities, newx, newy))) {
    entity_trigger(game, entity);
  } else if ((newx >= 0 && newx < game->map->w) &&
      (newy >= 0 && newy < game->map->h) &&
      sprite_at(game->map, newx, newy)->walkable) {
    game->character->x = newx;
    game->character->y = newy;
  }
}
