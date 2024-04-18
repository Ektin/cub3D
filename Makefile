CC=gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude #-pthread
LIBS = -Llib -lmlx -lft -lX11 -lXext
ASANFLAGS = -fsanitize=address
NAME = cub3D 
SRC = cub3D.c \
	parse_file.c \
	parse_map.c \
	errors.c \
	errors2.c \
	debug.c \
	parse_file_2.c \
	read_file.c \
	map_check.c \
	init.c \
	init2.c \
	events.c \
	events2.c \
	events3.c \
	point.c \
	distance.c \
	distance2.c \
	math.c \
	math2.c \
	math3.c \
	ray.c \
	draw_picture.c \
	draw2.c \

OBJ = $(SRC:.c=.o)
HEADER = include/cub3D.h
LIBDIR = mlx
LIBFT = src/libft
NORM = /bin/norminette

.PHONY: all clean fclean re lib asan libft

all: libft lib $(NAME)

asan: CFLAGS += -fsanitize=address
asan: LIBS += -fsanitize=address
asan: all

libft:
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a lib

lib:
	cd $(LIBDIR) && make
	cp $(LIBDIR)/libmlx.a lib/

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $@ $(LIBS)
	make NORM

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

NORM:
	@if [ "$(wildcard $(NORM))" != "" ]; then \
		$(NORM) $(SRC) $(HEADER); \
	fi

clean:
	rm -f $(OBJ) 
	rm -f src/libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -rf lib/*

re: fclean all
