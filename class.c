#include "main.h"

/* TODO read from a file */
static t_class* class_list(void) {
  static t_class list[] = {
    {"warrior", 100, 0, {"res/warrior.gif", 80, 100, NULL}},
    {"clerc", 100, 0, {"res/clerc.gif", 350, 100, NULL}},
    {"magician", 100, 0, {"res/magician.gif", 80, 300, NULL}},
    {"ninja", 100, 0, {"res/ninja.gif", 350, 300, NULL}},
    {NULL, 0, 0, {NULL, 0, 0, NULL}}
  };
  return list;
}

t_class* class_init(void) {
  t_class* list = class_list();
  for (int i = 0; list[i].name; ++i) {
    list[i].menu.surface = ximg_load(list[i].menu.img);
  }
  return list;
}

void class_quit(void) {
  t_class* list = class_list();
  for (int i = 0; list[i].name; ++i) {
    SDL_FreeSurface(list[i].menu.surface);
  }
}
/* TODO cleanup, SDL_FreeSurface */
