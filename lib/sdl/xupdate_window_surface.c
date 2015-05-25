#include "../../main.h"

void xupdate_window_surface(SDL_Window* window) {
  if (SDL_UpdateWindowSurface(window) < 0) {
    printf("Can't draw to window : %s\n", SDL_GetError());
    exit(1);
  }
}