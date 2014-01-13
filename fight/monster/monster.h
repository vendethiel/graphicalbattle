#ifndef __FIGHT_MONSTER_H__
# define __FIGHT_MONSTER_H__

typedef enum {
	MOB_JIRACHI
} e_mob;

typedef struct s_monster {
	e_mob	id;
	char	*name;
	int	hp;
	int	mp;
	/* script ?? */
} t_monster;

extern t_monster	g_monsters[];

t_monster	*monster_get(e_mob);
void monster_play(t_game *);

#endif /* !__FIGHT_MONSTER_H__ */