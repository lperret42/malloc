ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
CC = gcc
FLAGS = -Wall -Wextra -Werror
DLFLAGS= -shared -fPIC

SRC_PATH = ./src/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

SRC = malloc.c free.c realloc.c show_alloc_mem.c\
	  page.c block.c get_infos.c get_infos_2.c

OBJ	= $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(OBJ)
	@$(CC) $(FLAGS) $(DLFLAGS) -o $@ $(OBJ)
	@echo "\033[32mLinking & indexing" [ $(NAME) ] "\033[0m"
	gcc -Iincludes src/main.c $(NAME)

obj:
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(FLAGS) -I$(INCLUDES_PATH) -o $@ -c $<
	@echo "\033[33mCompiling" [ $< ] "\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[33mCleaning object files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[33mCleaning .so file" [ $(NAME) ] "\033[0m"
	@rm -rf a.out

re: fclean all

.PHONY: all clean fclean re
