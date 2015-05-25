#include "main.h"

#define MAX_DISPLAY 15
#define MAX_TILES 33

t_map *map_from_string(char *str, t_character *character) {
  t_map *map;
  int i, j, w, h, total;

  for (w = i = 0, h = 1; str[i]; ++i) {
    if (str[i] == '\n' && str[i + 1]) {
      ++h;
			if (!w) {
				/* take the first width as the "correct" width */
				w = i;
			}
		}
  }
  map = xcalloc(1, sizeof(t_map));
  map->tilesets = xcalloc(h, sizeof(t_tileset));
  map->w = w;
  map->h = h;
  for (total = i = 0; i < h; ++i) {
    map->tilesets[i].tiles = xcalloc(w, sizeof(char));
    for (j = 0; j < w; ++j, ++total) {
      if (str[total] == '+') {
				/* set the character's position */
        character->y = i;
        character->x = j;
        str[total] = ' '; /* ... and just pretend it was grass */
      }
      map->tilesets[i].tiles[j] = str[total];
    }
    ++total; /* skip \n */
  }
  return map;
}

void map_init(void) {
	sprite_init_maps();
}

void map_draw(t_game *game) {
  int base_i, base_j, i, j, max_i, max_j, off_i, off_j;

	/* this piece of code is responsible for the scrolling part */
	/* i and j are the "real" coordinates */
	/* off_i and off_j are the "relative" coordinates (relative to the scrolling) */

  base_i = game->character->y < MAX_DISPLAY ? 0 : game->character->y - MAX_DISPLAY;
  max_i = base_i + MAX_TILES; /* how far are we seeing? */
  if (max_i >= game->map->h) {
		/* if it's further than the map's height, fix it up */
    base_i = game->map->h - MAX_TILES;
		max_i = base_i + MAX_TILES; /* recalculate */
	}

	base_j = game->character->x < MAX_DISPLAY ? 0 : game->character->x - MAX_DISPLAY;
	max_j = base_j + MAX_TILES; /* how far are we seeing? */
	if (max_j >= game->map->w) {
		/* if it's further than the map's width, fix it up */
		base_j = game->map->w - MAX_TILES;
		max_j = base_j + MAX_TILES; /* recalculate */
	}

  for (off_i = 0, i = base_i; i < max_i; ++i, ++off_i) { /* fuck offffffff */
    for (off_j = 0, j = base_j; j < max_j; ++j, ++off_j) {
      sprite_display_at(game->screen,
                        sprite_get(game->map->tilesets[i].tiles[j]),
												off_j, off_i);
		}
  }
  sprite_display_at(game->screen, game->character->sprite,
                    game->character->x - max_j + MAX_TILES,
                    game->character->y - max_i + MAX_TILES);
}
