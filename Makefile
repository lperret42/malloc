ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
CC = gcc
FLAGS = -Wall -Wextra -Werror
DLFLAGS= -shared -fPIC

LIBFT_PATH = ./libft/
LIBFT_H = -I$(LIBFT_PATH)/includes
LIBFT_A = $(LIBFT_PATH)libftprintf.a
LIBFT_LINK = -L$(LIBFT_PATH) -lftprintf

SRC_PATH = ./src/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

SRC = malloc.c free.c realloc.c show_alloc_mem.c\
	  page.c block.c get_infos.c get_infos_2.c show_alloc_mem_tools.c

OBJ	= $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(LIBFT_A) $(OBJ)
	@$(CC) $(FLAGS) $(DLFLAGS) -o $@ $(LIBFT_LINK) $(LIBFT_A) $(OBJ)
	@echo "\033[32mCompiling" [ $(NAME) ] "\033[0m"
	gcc -Iincludes $(LIBFT_A) $(NAME) src/main.c -o main
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test0.c -o test0
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test1.c -o test1
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test2.c -o test2
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test3.c -o test3
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test4.c -o test4
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test5.c -o test5
	gcc -Iincludes $(LIBFT_A) $(NAME) src/test6.c -o test6

obj:
	@mkdir $(OBJ_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(FLAGS) -I$(INCLUDES_PATH) $(LIBFT_H) -o $@ -c $<
	@echo "\033[33mCompiling" [ $< ] "\033[0m"

clean:
	make clean -C $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(TRASH)
	@echo "\033[33mCleaning object files" [ $(NAME) ] "\033[0m"

fclean: clean
	make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)
	@rm -rf a.out
	@rm -rf main
	@rm -rf test0
	@rm -rf test1
	@rm -rf test2
	@rm -rf test3
	@rm -rf test4
	@rm -rf test5
	@rm -rf test6
	@echo "\033[33mDelete" [ $(NAME) ]  "\033[0m"

re: fclean all
