CC		= gcc

SRC		= main.c \
		  map.c \
		  sprite.c \
		  character.c \
		  event.c \
		  game.c \
		  class.c \
		  menu/draw_menu.c \
		  menu/class/mc.c \
		  actions/triggers.c \
		  actions/tick.c \
		  actions/event/keydown.c \
		  fight/fight.c \
		  fight/monster/monster.c \
		  lib/xmalloc.c \
		  lib/err.c \
		  lib/readfile.c \
		  lib/sdl/rect.c \
		  lib/sdl/ximg_load.c \
		  lib/sdl/xupdate_window_surface.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Werror -pedantic -ansi -g


LIBS	= -L$(HOME)/SDLOL/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

NAME	= midgar

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: clean all

test: all
	./$(NAME)

gdb: all
	gdb $(NAME)

.PHONY: clean fclean test gdb
