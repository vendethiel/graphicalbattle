#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include "main.h"

typedef struct s_character {
	int	x;
	int	y;
	int	vx;
	int	vy;
	struct s_class	*class;
	struct s_sprite	sprite;
	int hp;
} t_character;

t_character	*character_init(void);
void	character_move(struct s_game *);

#endif /* !__CHARACTER_H__ */