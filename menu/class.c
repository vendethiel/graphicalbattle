#include "../main.h"

void draw_menu_class_select(t_game* game) {
  SDL_Surface* warrior;
  SDL_Surface* clerc;
  SDL_Surface* mage;
  SDL_Surface* ninja;

  warrior = ximg_load("res/warrior.gif");
  clerc = ximg_load("res/clerc.gif");
  mage = ximg_load("res/magician.gif");
  ninja = ximg_load("res/ninja.gif");
  SDL_BlitSurface(warrior, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(50, 100, 0, 0));
  SDL_BlitSurface(clerc, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(400, 100, 0, 0));
  SDL_BlitSurface(mage, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(50, 300, 0, 0));
  SDL_BlitSurface(ninja, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(400, 300, 0, 0));
  SDL_FreeSurface(warrior);
}

void draw_menu_class(t_game* game) {
  TTF_Font* font;
  SDL_Surface* text;
  SDL_Color color = {99, 0, 0, 0};

  font = TTF_OpenFont("./res/sixty.ttf", 45);
  text = TTF_RenderText_Blended(font, "Choose", color);
  SDL_BlitSurface(text, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(200, 0, 0, 0));
  draw_menu_class_select(game);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}
