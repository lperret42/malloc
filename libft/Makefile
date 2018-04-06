# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperret  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 15:02:38 by lperret           #+#    #+#              #
#    Updated: 2017/05/10 14:36:39 by lperret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
#DEBUG = yes

#ifeq ($(DEBUG),yes)
#	FLAGS += -g
#endif

SRC_PATH = ./src/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

LIBFT_PATH = ./libft/
LIBFT_H = -I$(LIBFT_PATH)
LIBFT_A = $(LIBFT_PATH)libft.a
LIBFT_LINK = -L$(LIBFT_PATH) -lft

SRC = conv_c.c\
	  conv_s.c\
	  conv_d.c\
	  conv_percent.c\
	  conv_o.c\
	  conv_x.c\
	  conv_p.c\
	  conv_u.c\
	  conv_b.c\
	  usual_tools.c\
	  parsing.c core.c\
	  ft_printf.c\
	  alpha.c\
	  digit.c\
	  signed_toa.c\
	  unsigned_toa.c\
	  utf.c\
	  trashers.c

OBJ	= $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(LIBFT_A) $(OBJ) 
	@libtool -v -static -o $@ $(LIBFT_A) $(OBJ)

obj:
	@mkdir $(OBJ_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(FLAGS) $(LIBFT_H) -I$(INCLUDES_PATH) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
