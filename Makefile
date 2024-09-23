NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I/usr/include -Imlx -I.

BONUS_INCLUDES = -I/usr/include -Imlx -I/bonus/.

MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm

SRC = PARSING/GNL/get_next_line.c PARSING/GNL/get_next_line_utils.c \
PARSING/flood_fill.c PARSING/ft_split.c PARSING/is_map_valid.c PARSING/parsing_utils.c \
so_long.c render_mvt.c w_a_s_d.c render_utils.c render_map.c \

OBJ = $(SRC:.c=.o)

BONUS_SRC = bonus/PARSING/GNL/get_next_line.c bonus/PARSING/GNL/get_next_line_utils.c \
bonus/PARSING/flood_fill_b.c bonus/PARSING/ft_split.c \
bonus/PARSING/is_map_valid_b.c bonus/PARSING/parsing_utils_b.c \
bonus/so_long_b.c bonus/render_mvt_b.c bonus/wasd_b.c \
bonus/render_utils_b.c bonus/render_map_b.c bonus/ft_itoa.c\

BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBS = FT_PRINT/ftprintf.a mlx/libmlx.a

EXEC = so_long

EXEC_BONUS = so_long_bonus

all : $(EXEC)

$(LIBS):
	$(MAKE) -C mlx
	$(MAKE) -C FT_PRINT

$(EXEC) : $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $(EXEC)

bonus : $(EXEC_BONUS)

$(EXEC_BONUS) : $(BONUS_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) $(LIBS) $(MLX_FLAGS) -o $(EXEC_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(MAKE) -C FT_PRINT clean
	$(MAKE) -C mlx clean
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(EXEC)
	rm -rf $(EXEC_BONUS)
	$(MAKE) -C FT_PRINT fclean

re : fclean all

re_bonus : fclean bonus

.PHONY: all clean fclean re_bonus re bonus
