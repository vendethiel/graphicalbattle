#ifndef __TRIGGERS_MAIN_H__
# define __TRIGGERS_MAIN_H__

typedef void(*trigger)(t_game *);

extern trigger g_triggers[];

void	trigger_mob_jirachi(t_game *);

#endif /* !__TRIGGERS_MAIN_H__ */