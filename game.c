#include "main.h"

t_game* game_init(SDL_Window* window) {
  t_game* game;
  char* map_text, * entities_text;

  map_text = readfile("map.txt");
  entities_text = readfile("entities.txt");
  game = xcalloc(1, sizeof *game);
  game->map = map_from_string(map_text);
  game->character = character_init();
  game->window = window;
  game->screen = SDL_GetWindowSurface(game->window);
  game->state = GAME_MENU;
  game->classes = class_init();
  game->entities = entities_from_string(game, entities_text);
  return game;
}

t_tick g_tick_fns[] = {{GAME_MENU, tick_game_menu},
                       {CLASS_MENU, tick_class_menu},
                       {MAP, tick_map},
                       {MAP_MENU, tick_map_menu},
                       {FIGHT, tick_fight},
                       {GAMEOVER, tick_gameover},
                       {0, NULL}};

void game_tick(t_game* game) {
  for (int i = 0; g_tick_fns[i].fn; ++i) {
    // TODO index `g_tick_fns[game->state]` or something
    if (g_tick_fns[i].state == game->state) {
      g_tick_fns[i].fn(game);
      xupdate_window_surface(game->window);
      return;
    }
  }
  err("Game got into corrupted state. Aborting ...");
}

void game_quit(t_game* game) {
  // TODO clear fight if it's still here
  class_quit();
  SDL_DestroyWindow(game->window);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
