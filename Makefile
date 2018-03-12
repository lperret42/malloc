ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
CC = gcc
FLAGS = -Wall -Wextra -Werror
DLFLAGS= -shared -fPIC
DEBUG = yes

ifeq ($(DEBUG),yes)
	FLAGS += -g
endif

SRC_PATH = ./src/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

SRC = malloc.c

OBJ	= $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(OBJ)
	@$(CC) $(FLAGS) $(DLFLAGS) -o $@ $(OBJ)
	@echo "\033[32mLinking & indexing" [ $(NAME) ] "\033[0m"

obj:
	@mkdir $(OBJ_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(FLAGS) -I$(INCLUDES_PATH) -o $@ -c $<
	@echo "\033[33mCompiling" [ $< ] "\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[33mCleaning object files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[33mCleaning .so file" [ $(NAME) ] "\033[0m"

re: fclean all

.PHONY: all clean fclean re
