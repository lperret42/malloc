ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
CC = gcc
FLAGS = -Wall -Wextra -Werror
DEBUG = yes

ifeq ($(DEBUG),yes)
	FLAGS += -g
endif

TRASH = info .DS_Store $(NAME).dSYM

SRC_PATH = ./src/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

LIBFT_PATH = ./ft_printf/
LIBFT_H = -I$(LIBFT_PATH)/includes
LIBFT_A = $(LIBFT_PATH)libftprintf.a
LIBFT_LINK = -L$(LIBFT_PATH) -lftprintf


SRC = main.c malloc.c

OBJ	= $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(LIBFT_A) $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(LIBFT_A) $(OBJ)
	@echo "\033[32mLinking & indexing" [ $(NAME) ] "\033[0m"

obj:
	@mkdir $(OBJ_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(FLAGS) $(LIBFT_H) -I$(INCLUDES_PATH) -o $@ -c $<
	@echo "\033[33mCompiling" [ $< ] "\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(TRASH)
	@make clean -C $(LIBFT_PATH)
	@echo "\033[33mCleaning object files" [ $(NAME) ] "\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[33mDelete" [ $(NAME) ]  "\033[0m"

re: fclean all

.PHONY: all clean fclean re
