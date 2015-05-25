#include "../main.h"

void tick_game_menu(t_game* game) {
  SDL_Surface* menu = NULL;

  menu = ximg_load("res/texture.jpg");
  SDL_BlitSurface(menu, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(0, 0, 0, 0));
  draw_menu(game);
  sound_menu();
}

void tick_map(t_game* game) {
  character_move(game);
  map_draw(game);
}

void tick_map_menu(t_game* game) {
  if (game) {
  }
}

void tick_fight(t_game* game) {
  fight_bg(game);
  if (game->fight->monster->hp > 1)
    monster_play(game);
}

void tick_class_menu(t_game* game) {
  SDL_Surface* menu = NULL;

  menu = ximg_load("res/texture.jpg");
  SDL_BlitSurface(menu, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(0, 0, 0, 0));

  draw_menu_class(game);
}
