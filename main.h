#ifndef __MAIN_H__
# define __MAIN_H__

# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "include/SDL2/SDL.h"
# include "include/SDL2/SDL_image.h"
# include  "include/SDL2/SDL_ttf.h"
# include  "include/SDL2/SDL_mixer.h"


# define TILE_HEIGHT 16
# define TILE_WIDTH 16

struct s_sprite;
struct s_map;
struct s_character;
struct s_game;
struct s_monster;
struct s_fight;
struct s_class;

# include "lib/main.h"
# include "lib/sdl/main.h"

# include "sprite.h"
# include "class.h"
# include "character.h"
# include "map.h"
# include "game.h"
# include "event.h"

# include "actions/triggers.h"
# include "actions/tick.h"
# include "actions/event/keydown.h"

# include "fight/monster/monster.h"
# include "fight/fight.h"

#include "menu/draw_menu.h"
#include "menu/class/mc.h"

SDL_Window *create_window(void);

#endif /* !__MAIN_H__ */