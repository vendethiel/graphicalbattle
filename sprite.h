#pragma once

typedef struct s_sprite {
  char id;
  int mapid;
  int x;
  int y;
  int walkable;
} t_sprite;

extern SDL_Surface* sprite_maps[];

extern t_sprite g_sprites[];

void sprite_display_at(SDL_Surface*, t_sprite*, int, int);
void sprite_init_maps(void);
t_sprite* sprite_get(char);
t_sprite* sprite_at(struct s_map*, int, int);
