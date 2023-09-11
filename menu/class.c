#include "../main.h"

static void draw_menu_class_select(t_game* game) {
  static SDL_Rect* whole, * to;
  if (!whole) whole = sdlh_rect(0, 0, 512, 512);
  if (!to) to = sdlh_rect(0, 0, 0, 0);
  for (int i = 0; game->classes[i].name; ++i) {
    t_class_menu* class_menu = &game->classes[i].menu;
    to->x = class_menu->x;
    to->y = class_menu->y;
    SDL_BlitSurface(class_menu->surface, whole, game->screen, to);
  }
}

static void draw_menu_class_select_pointer(t_game* game) {
  static SDL_Surface* asterisk;
  static SDL_Rect* whole, * to;
  if (!asterisk) asterisk = draw_text("*");
  if (!whole) whole = sdlh_rect(0, 0, 512, 512);
  if (!to) to = sdlh_rect(0, 0, 0, 0);

  t_class* class = character_class(game);
  to->x = class->menu.x - 30;
  to->y = class->menu.y;
  SDL_BlitSurface(asterisk, whole, game->screen, to);
}

void draw_menu_class(t_game* game) {
  static SDL_Surface *menu;
  static SDL_Rect *whole, *to;
  if (!menu) menu = ximg_load("res/texture.jpg");
  if (!whole) whole = sdlh_rect(0, 0, 512, 512);
  if (!to) to = sdlh_rect(0, 0, 0, 0);
  SDL_BlitSurface(menu, whole, game->screen, to);

  static SDL_Surface *text;
  if (!text) text = draw_text("Choose");

  to->x = 200;
  SDL_BlitSurface(text, whole, game->screen, to);
  to->x = 0; /* need to restore it for subsequent calls */
  
  draw_menu_class_select(game);
  draw_menu_class_select_pointer(game);
  /* TODO somehow
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
  */
}
