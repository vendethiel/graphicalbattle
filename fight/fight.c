#include "../main.h"

static t_fight* fight_init(t_monster* monster) {
  t_fight* fight;

  fight = xmalloc(sizeof *fight);
  fight->monster = monster;
  fight_change_state(fight, turn_player); // TODO some kind of level/stat-based stuff
  return fight;
}

void fight_start(t_game* game, t_monster* monster) {
  game->state = FIGHT;
  game->fight = fight_init(monster);
}

void fight_player_attack(t_game* game) {
  if (!game->fight || game->fight->state != turn_player) {
    return;
  }

  game->fight->monster->hp -= 20;
  printf("remaining monster hp: %d\n", game->fight->monster->hp);
  if (game->fight->monster->hp < 1) {
    monster_remove(game); // XXX #11 this shouldn't be how this works
    fight_end_to(game, MAP);
  } else {
    fight_change_state(game->fight, turn_player_after);
  }
}

void fight_change_state(t_fight* fight, e_fight_state state) {
  printf("changed fight state! %d -> %d\n", fight->state, state);
  fight->menu = menu_fight_attack;
  fight->state = state;
  fight->ticker = 0;
}

void fight_end_to(t_game* game, e_state state) {
  // TODO delete/dealloc fight properly, the have a mob and w/e else
  free(game->fight);
  game->fight = NULL;
  game->state = state;
}

void draw_in_battle(t_game* game) {
  TTF_Font* font;
  SDL_Surface* text;
  SDL_Color color = {99, 0, 0, 0};

  font = TTF_OpenFont("./res/sixty.ttf", 45);
  text = TTF_RenderText_Blended(font, "Attack", color);
  SDL_BlitSurface(text, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(200, 300, 0, 0));
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}

void fight_bg(t_game* game) { /* @TODO refactor & finish */
  static SDL_Surface* g_bg;
  static SDL_Surface* g_bg_text;
  static SDL_Surface* warrior;
  static SDL_Surface* ninja;

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

void fight_bg_text() {
}
