#ifndef __LIB_SDL_MAIN_H__
# define __LIB_SDL_MAIN_H__

SDL_Rect	*sdlh_rect(int, int, int, int);
SDL_Surface	*ximg_load(char *);
void	xupdate_window_surface(SDL_Window *);

#endif /* !__LIB_SDL_MAIN_H__ */