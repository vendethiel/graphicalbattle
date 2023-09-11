#include "../main.h"

typedef struct s_menu_fight {
  e_menu_fight_state state;
  char* text;
  int x, y;
  SDL_Surface *surface;
} t_menu_fight;

static t_menu_fight actions[] = {
  { menu_fight_attack, "Attack", 50, 300, NULL },
  { menu_fight_flee,   "Flee",   50, 350, NULL },
  { -1,                 NULL,     0,   0, NULL },
};

void draw_menu_fight(t_game* game) {
  static SDL_Surface* asterisk;
  static SDL_Rect* whole, * to;
  if (!asterisk) asterisk = draw_text("*");
  if (!whole) whole = sdlh_rect(0, 0, 512, 512);
  if (!to) to = sdlh_rect(0, 0, 0, 0);
  
  for (int i = 0; actions[i].text; ++i) {
    t_menu_fight* action = actions + i;

    if (!action->surface) {
      action->surface = draw_text(action->text);
    }

    to->x = action->x;
    to->y = action->y;
    SDL_BlitSurface(action->surface, whole, game->screen, to);

    if (game->fight->menu == action->state) {
      to->x -= 30; /* the asterisk is on the left */
      SDL_BlitSurface(asterisk, whole, game->screen, to);
    }
  }
  // TODO additional class-based actions etc?
  // TODO maybe store game->fight->actions, so that the enum is correct?
  // TODO maybe une negative numbers for the built-in enum values like attack and flee?
  // TODO use a submenu like MAGIC that'd have its own index
}
