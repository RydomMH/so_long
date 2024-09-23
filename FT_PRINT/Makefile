
NAME = ftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_hexalower.c ft_hexaupper.c ft_printf.c ft_putchar.c ft_putnbr.c \
ft_putnbr4u.c ft_putstr.c ft_usefunction.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all