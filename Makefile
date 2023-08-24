CC		= clang

SRC		= $(wildcard *.c) \
				$(wildcard lib/*.c) $(wildcard lib/sdl/*.c) \
				$(wildcard menu/*.c) \
				$(wildcard actions/*.c) $(wildcard actions/event/*.c) \
				$(wildcard fight/*.c) $(wildcard fight/monster/*.c)

OBJ		= $(SRC:.c=.o)

CFLAGS	= `sdl2-config --cflags` -W -Wall -Wextra -g -Wno-newline-eof -Wno-deprecated-declarations

LIBS	= `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lSDL2_mixer

NAME	= midgar

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

test: all
	./$(NAME)

gdb: all
	gdb $(NAME)
lldb: all
	lldb $(NAME)

.PHONY: clean fclean test gdb
