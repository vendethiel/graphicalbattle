#include "../main.h"

static void fight_log_remove_single(t_fight_log *log) {
  SDL_FreeSurface(log->surface);
  free(log->text);
  free(log);
}

void fight_log_clear(t_fight_log *log) {
  while (log) {
    t_fight_log *current = log;
    log = current->next;

    fight_log_remove_single(current);
  }
}

static void fight_log_trim(t_fight_log* log, int max) {
  t_fight_log *prev;
  int i;

  prev = NULL;
  for (i = 0; log; ++i) {
    if (i >= max) { // >= because max is 1-indexed, so 5th is i=4
      if (prev) {
        prev->next = NULL;
        fight_log_clear(log);
      }
      // TODO else warn (means a bug, or a max of 0 which makes no sense)
      // other solution would be to take t_fight_log** log, like a linked list
      break;
    }
    prev = log;
    log = log->next;
  }
}

void fight_log_add(t_fight* fight, char* text) {
  t_fight_log *log;

  log = xmalloc(sizeof *log);
  log->next = fight->log;
  log->text = text;
  log->surface = NULL;

  fight->log = log;
  fight_log_trim(log, FIGHT_LOG_MAX_ENTRIES);
}

void fight_log(t_game* game) {
  static SDL_Color color = {255, 255, 255, 0};
  static TTF_Font *font;
  static SDL_Rect *to;
  t_fight_log *log;
  int i;

  if (!font) font = TTF_OpenFont("./res/sixty.ttf", 20);
  if (!to) to = sdlh_rect(200, 0, 0, 0);

  for (i = 0, log = game->fight->log; log; ++i, log = log->next) {
    if (!log->surface)
      log->surface = TTF_RenderText_Blended(font, log->text, color);
    to->y = 250 + i * 30;
    SDL_BlitSurface(log->surface, NULL, game->screen, to);
  }
}
