#ifndef __FIGHT_H__
# define __FIGHT_H__

typedef struct s_fight {
	t_monster	*monster;
} t_fight;

void	fight_start(t_game *, t_monster *);
void	fight_bg();
void	draw_in_battle(t_game *);

#endif /* !__FIGHT_H__ */