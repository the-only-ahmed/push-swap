# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 21:28:36 by ael-kadh          #+#    #+#              #
#    Updated: 2013/12/22 03:59:50 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = main.c fn_swap.c sort.c init.c flags.c spaces.c actions.c verifications.c
HEAD = swap.h
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -I libft/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
