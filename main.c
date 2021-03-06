#include "main.h"

SDL_Window* create_window(void) {
  SDL_Window* window;

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
  if (TTF_Init() == -1)
    err("TTF_Init error");
  window = SDL_CreateWindow("Midgar", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, 512, 512,
                            /*map->w * TILE_WIDTH, map->h * TILE_HEIGHT,*/
                            SDL_WINDOW_SHOWN /*SDL_WINDOW_BORDERLESS*/
                            );
  if (!window) {
    printf("Unable to create window : %s\n", SDL_GetError());
    exit(1);
  }
  map_init();
  return window;
}

int main() {
  SDL_Event event;
  SDL_Window* window;
  t_game* game;

  window = create_window();
  game = game_init(window);
  for (int cont = 1; cont;) {
    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        cont = 0;
      else if (event.type == SDL_KEYDOWN)
        event_keydown(event, game);
      else if (event.type == SDL_WINDOWEVENT)
        game->screen = SDL_GetWindowSurface(window);
    if (cont)
      game_tick(game);
  }
  game_quit(game);
  return 0;
}
