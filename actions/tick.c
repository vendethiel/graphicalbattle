#include "../main.h"

void tick_game_menu(t_game* game) {
  static SDL_Surface* menu;
  if (!menu) menu = ximg_load("res/texture.jpg");
  SDL_BlitSurface(menu, sdlh_rect(0, 0, 512, 512), game->screen,
                  sdlh_rect(0, 0, 0, 0));
  draw_menu(game);
  sound_menu();
}

void tick_map(t_game* game) {
  character_move(game);
  map_draw(game);
}

void tick_map_menu(t_game* game) {
  if (game) {
  }
}

void tick_fight(t_game* game) {
  if (!game->fight) {
    // TODO log
    game->state = MAP; // should *never* happen
    return;
  }

  // TODO anim here
  fight_bg(game);

  if (game->fight->state == turn_player) {
    draw_menu_fight(game);
    return; /* skip ticker stuff */
  }

  if (game->fight->ticker == FIGHT_WAIT_TICKS) {
    game->fight->ticker = 0;
    // TODO show text based on fight state
    switch (game->fight->state) {
      case turn_monster:
        monster_play(game);
        break;
      case turn_monster_after: // monster turn ended, player is next
        fight_change_state(game->fight, turn_player);
        break;
      case turn_player_after: // player turn ended, monster is next
        fight_change_state(game->fight, turn_monster);
        break;
      default:
          // TODO error here

          ;
    }
  } else { // not at FIGHT_WAIT_TICKS yet
    game->fight->ticker++;
  }
}

void tick_class_menu(t_game* game) {
  draw_menu_class(game);
}

void tick_gameover(t_game* game) {
  if (game) {
    printf("You lost!\n");
    exit(0);
  }
}
