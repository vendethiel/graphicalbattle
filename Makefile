CXX		= clang

SRC		= $(wildcard *.c) \
				$(wildcard lib/*.c) $(wildcard lib/sdl/*.c) \
				$(wildcard menu/*.c) \
				$(wildcard actions/*.c) $(wildcard actions/event/*.c) \
				$(wildcard fight/*.c) $(wildcard fight/monster/*.c)

OBJ		= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -g -Wno-newline-eof


LIBS	= -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

NAME	= midgar

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

test: all
	./$(NAME)

gdb: all
	gdb $(NAME)

.PHONY: clean fclean test gdb
