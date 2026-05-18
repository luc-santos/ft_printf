NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
SRC = ft_printf.c			\
	ft_printf_handler.c		\
	ft_printf_utils.c		\
	ft_printf_numbers.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all