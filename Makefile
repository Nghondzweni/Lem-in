# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/09 12:53:37 by tnghondz          #+#    #+#              #
#    Updated: 2018/09/09 16:06:55 by tnghondz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

RCS_DIR		= ./resources

SRCS_DIR	:= ./srcs/initialize.c
SRCS_DIR	+= ./srcs/lem_in.c
SRCS_DIR	+= ./srcs/error_check.c
SRCS_DIR	+= ./srcs/read.c
SRCS_DIR	+= ./srcs/navigate.c
SRCS_DIR	+= ./srcs/solution.c
SRCS_DIR	+= ./srcs/make_list.c

LIBFT_DIR	= ./libft

INCLUDES	= ./includes

FLAGS = -Wextra -Werror -Wall  -I./includes

CC = gcc

all: $(NAME)
$(NAME):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(CC) -o $(NAME) $(FLAGS) $(SRCS_DIR) libft/libft.a
	clear

clean:
	@make clean -C libft
fclean:
	@make fclean -C libft
	@rm -f $(NAME)

re:	fclean all
