CC=gcc
SRC_FILES = get_next_line.c #get_next_line_utils.c
CFLAGS = -Wall -Werror -Wextra -I../libft
OFILES = $(patsubst %.c, %.o, $(SRC_FILES))

all: $(OFILES)

re: fclean all

fclean: clean

clean:
	rm -f $(OFILES)
