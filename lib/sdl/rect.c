#include "../../main.h"

SDL_Rect *sdlh_rect(int x, int y, int w, int h) {
  SDL_Rect *rect;

  rect = xmalloc(sizeof(SDL_Rect));
  rect->x = x;
  rect->y = y;
  rect->w = w;
  rect->h = h;
  return (rect);
}
