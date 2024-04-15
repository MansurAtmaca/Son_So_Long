SRCS = source/main.c source/map_funcs.c source/check_funcs.c source/controls.c source/controls_2.c source/free.c source/ft_split.c
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx -lz
CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
GNL = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c 
PRINTF =$(wildcard printf/*c)
GNLOBJS = $(GNL:.c=.o)
PRINTFOBJS = $(PRINTF:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = so_long
MLX = ./minilibx/libmlx.a

all : $(MLX) $(NAME)

$(MLX) :
	make -sC ./minilibx

$(NAME) : $(OBJS) $(GNLOBJS) $(PRINTFOBJS)
	gcc $(OBJS) $(GNLOBJS) $(PRINTFOBJS)  $(LFLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/*.o
	rm -rf ./printf/*.o
	make clean -C ./minilibx


norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re
