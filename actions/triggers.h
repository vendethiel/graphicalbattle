#pragma once

typedef void(*trigger)(t_game *);

extern trigger g_triggers[];

void	trigger_mob_jirachi(t_game *);
