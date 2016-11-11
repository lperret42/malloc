NAME = libft.a
PATH_C = ./
PATH_H = ./
CC = gcc
FLAGS = -Wall -Werror -Wextra -I$(PATH_H)
SRC = *.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(addprefix $(PATH_C), $(SRC))
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc $(FLAGS) -o exe $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) exe

re: fclean all
