#include "../main.h"

void fight_log_add(t_fight* fight, char* text) {
  t_fight_log *log;

  log = xmalloc(sizeof *log);
  log->next = fight->log;
  log->text = text;
  log->surface = NULL;

  fight->log = log;
  // TODO ensure a maximum size
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
