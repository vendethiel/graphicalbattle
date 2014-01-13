#ifndef __ACTIONS_EVENT_KEYDOWN_H__
# define __ACTIONS_EVENT_KEYDOWN_H__

void	event_keydown_gamemenu(SDL_Event, t_game *);
void	event_keydown_classmenu(SDL_Event, t_game *);
void	event_keydown_map(SDL_Event, t_game *);
void	event_keydown_fight(SDL_Event, t_game *);
void	event_keydown_void(SDL_Event, t_game *);

#endif /* !__ACTIONS_EVENT_KEYDOWN_H__ */