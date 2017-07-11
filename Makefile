# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 11:33:06 by abarriel          #+#    #+#              #
#    Updated: 2017/07/11 23:41:52 by abarriel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

SRC		= minishell.c init.c load.c print.c exec.c builtin.c env.c find.c

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ./includes/minishell.h

CFLAGS	=  -Wall -Wextra -I./includes/ -Ilibft/includes/

all: makefile libft $(NAME)

libft:
	@make -C libft

$(NAME): libft $(OBJ) $(INCLUDES)
	@gcc $(OBJ) -o $(NAME)  -Llibft -lft
	@echo ""

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C libft

re: fclean all

.PHONY: clean fclean re libft all
