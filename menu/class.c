#include "../main.h"

static void draw_menu_class_select(t_game* game) {
  for (int i = 0; game->classes[i].name; ++i) {
    t_class_menu* class_menu = &game->classes[i].menu;
    SDL_BlitSurface(class_menu->surface, sdlh_rect(0, 0, 512, 512), game->screen,
        sdlh_rect(class_menu->x, class_menu->y, 0, 0));
  }
}

static void draw_menu_class_select_pointer(t_game* game) {
  static SDL_Surface* asterisk;
  if (!asterisk) asterisk = draw_text("*");

  t_class* class = character_class(game);
  SDL_BlitSurface(asterisk, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(class->menu.x - 30, class->menu.y, 0, 0));
}

void draw_menu_class(t_game* game) {
  static SDL_Surface* menu;
  if (!menu) menu = ximg_load("res/texture.jpg");
  SDL_BlitSurface(menu, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(0, 0, 0, 0));

  static SDL_Surface* text;
  if (!text) text = draw_text("Choose");

  SDL_BlitSurface(text, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(200, 0, 0, 0));
  
  draw_menu_class_select(game);
  draw_menu_class_select_pointer(game);
  /* TODO somehow
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
  */
}
