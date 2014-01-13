#include "main.h"

#define MAX_DISPLAY 15
#define MAX_TILES 33

t_map	*map_from_string(char *str, t_character *character)
{
	t_map	*map;
	int	i, j, w, h, total;

	for (w = i = 0, h = 1; str[i]; ++i)
	{
		if (str[i] == '\n')
			++h;
		if (str[i] == '\n' && !w)
			w = i;
	}
	map = xcalloc(1, sizeof(t_map));
	map->tilesets = xcalloc(h, sizeof(t_tileset));
	map->w = w; map->h = h;
	for (total = i = 0; i < h; ++i)
	{
		map->tilesets[i].tiles = xcalloc(w, sizeof(char));
		for (j = 0; j < w; ++j, ++total)
		{
			if (str[total] == '+')
			{
				character->y = i; character->x = j;
				str[total] = ' ';
			}
			map->tilesets[i].tiles[j] = str[total];
		}
		++total; /* \n */
	}
	return (map);
}

void	map_init()
{
	sprite_init_maps();
}

void	map_draw(t_game *game)
{
	int	i, j, max_i, max_j, off_i, off_j;

	i = game->character->y < MAX_DISPLAY ? 0 : game->character->y - MAX_DISPLAY;
	max_i = i + MAX_TILES;
	if (max_i > game->map->h) i = game->map->h - MAX_TILES, max_i = i + MAX_TILES;
	for (off_i = 0; i < max_i; ++i, ++off_i)
	{ /* fuck offffffff */
		j = game->character->x < MAX_DISPLAY ? 0 : game->character->x - MAX_DISPLAY;
		max_j = j + MAX_TILES;
		if (max_j > game->map->w) j = game->map->w - MAX_TILES, max_j = j + MAX_TILES;
		for (off_j = 0; j < max_j; ++j, ++off_j)
			sprite_display_at(game->screen, sprite_get(game->map->tilesets[i].tiles[j]), off_j, off_i);
	}
	sprite_display_at(game->screen, game->character->sprite, game->character->x - max_j + MAX_TILES, game->character->y - max_i + MAX_TILES);
}