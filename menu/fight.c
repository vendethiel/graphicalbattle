#include "../main.h"

typedef struct s_menu_fight {
  e_menu_fight_state state;
  char* text;
  int x, y;
  SDL_Surface *surface;
} t_menu_fight;

static t_menu_fight actions[] = {
  { menu_fight_attack, "Attack", 100, 100, NULL },
  { menu_fight_flee,   "Flee",   200, 100, NULL },
  { 0,                 NULL,     0, 0    , NULL },
};

void draw_menu_fight(t_game* game) {
  static SDL_Surface* asterisk;
  if (!asterisk) asterisk = draw_text("*");
  
  for (int i = 0; actions[i].text; ++i) {
    t_menu_fight* action = actions + i;

    if (!action->surface) {
      action->surface = draw_text(action->text);
    }

    SDL_BlitSurface(action->surface, sdlh_rect(0, 0, 512, 512), game->screen,
        sdlh_rect(action->x, action->y, 0, 0));

    if (game->fight->menu == action->state) {
      SDL_BlitSurface(asterisk, sdlh_rect(0, 0, 512, 512), game->screen,
          sdlh_rect(action->x - 30, action->y, 0, 0));
    }
  }
}
