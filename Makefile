ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft/
LIBFT_H = -I$(LIBFT_PATH)/includes
LIBFT_A = $(LIBFT_PATH)libft.a
LIBFT_LINK = -L$(LIBFT_PATH) -lft

SRC_PATH = ./src/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

SRC = malloc.c free.c realloc.c show_alloc_mem.c\
	  page.c block.c get_infos.c get_infos_2.c show_alloc_mem_tools.c

OBJ	= $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

SYMBOLIC_LINK = libft_malloc.so

all: $(NAME)

$(NAME): obj $(LIBFT_A) $(OBJ)
	@$(CC) $(FLAGS) $(DLFLAGS) -shared -o $@ $(LIBFT_LINK) $(LIBFT_A) $(OBJ)
	@echo "\033[32mLinking & indexing" [ $(NAME) ] "\033[0m"
	@ln -sf $(NAME) $(SYMBOLIC_LINK)
	@echo "\033[32mCreation of a symbolic link" [ $(SYMBOLIC_LINK) ]\
							"pointing to" [ $(NAME) ]  "\033[0m"
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/main.c -o main
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test0.c -o test0
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test1.c -o test1
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test2.c -o test2
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test3.c -o test3
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test4.c -o test4
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test5.c -o test5
	@gcc -Iincludes $(LIBFT_A) $(NAME) tests/test6.c -o test6

obj:
	@mkdir $(OBJ_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(FLAGS) -I$(INCLUDES_PATH) $(LIBFT_H) -o $@ -c $<
	@echo "\033[33mCompiling" [ $< ] "\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;31mCleaning object files" [ $(NAME) ] "\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(SYMBOLIC_LINK)
	@echo "\033[0;31mDelete" [ $(NAME) ]  "\033[0m"
	@echo "\033[0;31mDelete" [ $(SYMBOLIC_LINK) ]  "\033[0m"
	@make fclean -C $(LIBFT_PATH)
	@rm -rf a.out
	@rm -rf main
	@rm -rf test0
	@rm -rf test1
	@rm -rf test2
	@rm -rf test3
	@rm -rf test4
	@rm -rf test5
	@rm -rf test6

re: fclean all
