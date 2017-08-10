#include "../../main.h"

SDL_Surface* ximg_load(char* str) {
  SDL_Surface* img;

  img = IMG_Load(str);
  printf("LOAD %s.\n", str);
  if (!img) {
    printf("error loading '%s' : '%s'\n", str, IMG_GetError());
    exit(1);
  }
  return img;
}
