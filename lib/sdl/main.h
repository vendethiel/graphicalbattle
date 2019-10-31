#pragma once

SDL_Rect* sdlh_rect(int, int, int, int);
SDL_Surface* ximg_load(char*);
SDL_Surface* draw_text(char*);
void xupdate_window_surface(SDL_Window*);
