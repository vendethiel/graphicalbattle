#include "../main.h"

void fight_start(t_game *game, t_monster *monster) {
  t_fight *fight;

  fight = xcalloc(1, sizeof(t_fight));
  fight->monster = monster;
  game->state = FIGHT;
  game->fight = fight;
}

void draw_in_battle(t_game *game) {
  TTF_Font *font;
  SDL_Surface *text;
  SDL_Color color = {99, 0, 0, 0};

  font = TTF_OpenFont("./res/sixty.ttf", 45);
  text = TTF_RenderText_Blended(font, "Attack", color);
  SDL_BlitSurface(text, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(200, 300, 0, 0));
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}

void fight_bg(t_game *game) { /* @TODO refactor & finish */
  static SDL_Surface *g_bg;
  static SDL_Surface *g_bg_text;
  static SDL_Surface *warrior;
  static SDL_Surface *ninja;

  if (!g_bg)
    g_bg = ximg_load("res/battle_bg.png"),
    g_bg_text = ximg_load("res/battle_text.png"),
    warrior = ximg_load("res/warrior.gif"), ninja = ximg_load("res/ninja.gif");

  SDL_BlitSurface(g_bg, sdlh_rect(0, 0, 512, 341), game->screen,
                  sdlh_rect(0, 0, 0, 0));
  SDL_BlitSurface(g_bg_text, sdlh_rect(0, 0, 512, 171), game->screen,
                  sdlh_rect(0, 341, 0, 0));
  SDL_BlitSurface(warrior, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(50, 75, 0, 0));
  SDL_BlitSurface(ninja, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(400, 75, 0, 0));
  draw_in_battle(game);
}

/*
        TTF_Font *font = NULL;
        SDL_Surface *text = NULL;
        SDL_Color color = {99, 0, 0,0};

        font = TTF_OpenFont("./res/sixty.ttf", 65);
    text = TTF_RenderText_Blended(font, " Attack", color);
    SDL_BlitSurface(text, sdlh_rect(0, 0, 400, 300),
                game->screen, sdlh_rect(0, 0, 0, 0)
        );
    SDL_FreeSurface(text);
    TTF_CloseFont(font);
*/

void fight_bg_text() {}