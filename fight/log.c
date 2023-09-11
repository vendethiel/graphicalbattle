#include "../main.h"

void fight_log_add(t_fight* fight, char* text) {
  t_fight_log *log;

  log = xmalloc(sizeof *log);
  log->next = fight->log;
  log->text = text;

  fight->log = log;
  // TODO ensure a maximum size
}

void fight_log_clear(t_fight_log *log) {
  while (log) {
    t_fight_log *current = log;
    log = current->next;

    free(current->text);
    free(current);
  }
}