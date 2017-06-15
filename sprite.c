#include "main.h"

SDL_Surface* sprite_maps[] = {
    0,
};

/*   id,mapid,x,y, trigger*/
/* + = character */
t_sprite g_sprites[] = {
    /* ground */
    {' ', 0, 71, 103, 1},
    {'S', 0, 92, 233, 0},
    {'W', 0, 302, 32, 0},
    {'R', 0, 556, 945, 0},
    {'I', 0, 803, 152, 1},
    {'F', 0, 73, 452, 0},
    {'T', 0, 318, 116, 1},
    {'M', 0, 449, 984, 0},
    {'E', 0, 550, 31, 1},
    {'I', 0, 871, 195, 1},
    {'G', 0, 785, 195, 0},
    {'J', 0, 889, 177, 0},

    /* elements */
    {'P', 0, 25, 102, 0},
    {'B', 0, 437, 649, 0},

    /* char */
    {'+', 0, 44, 280, 0},

    /* mobs */
    {'?', 0, 384, 508, 2},

    {0, 0, 0, 0, 0},
};

void sprite_display_at(SDL_Surface* screen, t_sprite sprite, int w, int h) {
  SDL_BlitSurface(sprite_maps[sprite.mapid],
                  sdlh_rect(sprite.x, sprite.y, TILE_HEIGHT, TILE_WIDTH),
                  screen, sdlh_rect(w * TILE_WIDTH, h * TILE_HEIGHT, 0, 0));
}

void sprite_init_maps(void) {
  sprite_maps[0] = ximg_load("res/pokesprites.jpg");
}

#include <signal.h>
t_sprite sprite_get(char id) {
  int i;

  for (i = 0; g_sprites[i].id != 0; ++i) {
    if (g_sprites[i].id == id)
      return g_sprites[i];
  }

  printf("Sprite not found : '%c'\n", id);
  raise(SIGSEGV);
  return g_sprites[0];
}

t_sprite sprite_at(t_map* map, int x, int y) {
  return sprite_get(map->tilesets[y].tiles[x]);
}
