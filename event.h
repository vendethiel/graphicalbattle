#pragma once

typedef void (*event_fn)(SDL_Event, t_game *);
typedef struct {
  e_state state;
  event_fn fn;
} t_event;

extern t_event g_events[];
void event_keydown(SDL_Event, t_game *);
