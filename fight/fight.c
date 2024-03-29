#include <stdio.h>
#include "../main.h"
#include "damage.h"

static t_fight* fight_init(t_monster* monster) {
  t_fight* fight;

  fight = xmalloc(sizeof *fight);
  fight->monster = monster;
  fight->state = turn_player; // So that fight_change_state doesnt read uninit
  fight_change_state(fight, turn_player);
  // TODO some kind of level/stat-based stuff
  return fight;
}

void fight_start(t_game* game, t_monster* monster) {
  game->state = FIGHT;
  game->fight = fight_init(monster);
}

static void fight_player_attack(t_game* game) {
  char* text;
  int damage = fight_damage_player(game->character, game->fight->monster);

  int result = game->fight->monster->hp - damage;
  if (result <= 0)
    result = 0;

  asprintf(&text, "Dealing %d damage to %s (%d -> %d)",
            damage,
            monster_name(game->fight->monster),
            game->fight->monster->hp,
            result);
  game->fight->monster->hp = result;
  puts(text);

  if (game->fight->monster->hp <= 0) {
    free(text);
    // XXX #11 this shouldn't be how this works
    // HOWEVER, flee should leave the mob. Maybe it's ok?
    monster_remove(game);
    fight_end_to(game, MAP);
  } else {
    fight_log_add(game->fight, text);
    fight_change_state(game->fight, turn_player_after);
  }
}

static void fight_player_flee(t_game* game) {
  // TODO... unsure?
  fight_end_to(game, MAP);
}

void fight_player_act(t_game* game) {
  if (!game->fight || game->fight->state != turn_player) {
    return;
  }

  switch (game->fight->menu) {
  case menu_fight_attack:
    fight_player_attack(game);
    break;
  case menu_fight_flee:
    fight_player_flee(game);
    break;
  default:
    // TODO log
    // Invalid state, trust fight_change_state() to reset itself
    fight_change_state(game->fight, game->fight->state);
  }
}

void fight_change_state(t_fight* fight, e_fight_state state) {
  printf("changed fight state! %d -> %d\n", fight->state, state);
  fight->menu = menu_fight_attack;
  fight->state = state;
  fight->ticker = 0;
}

void fight_end_to(t_game* game, e_state state) {
  // TODO delete/dealloc fight properly, the mob and w/e else
  fight_log_clear(game->fight->log);
  free(game->fight);
  game->fight = NULL;
  game->state = state;
}

void fight_bg(t_game* game) { /* @TODO refactor & finish */
  static SDL_Surface* g_bg;
  static SDL_Surface* g_bg_text;
  static SDL_Surface* warrior;
  static SDL_Surface* ninja;

  // TODO asset loader
  if (!g_bg) g_bg = ximg_load("res/battle_bg.png");
  if (!g_bg_text) g_bg_text = ximg_load("res/battle_text.png");
  if (!warrior) warrior = ximg_load("res/warrior.gif");
  if (!ninja) ninja = ximg_load("res/ninja.gif");

  SDL_BlitSurface(g_bg, sdlh_rect(0, 0, 512, 341), game->screen,
                  sdlh_rect(0, 0, 0, 0));
  SDL_BlitSurface(g_bg_text, sdlh_rect(0, 0, 512, 171), game->screen,
                  sdlh_rect(0, 341, 0, 0));
  SDL_BlitSurface(warrior, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(50, 75, 0, 0));
  SDL_BlitSurface(ninja, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(400, 75, 0, 0));
}
