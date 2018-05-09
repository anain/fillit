# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anain <anain@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 03:28:17 by anain             #+#    #+#              #
#    Updated: 2017/03/09 18:23:52 by asavann          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_check.c ft_filltab.c ft_finaltab.c ft_map.c \
ft_findpos.c ft_strcmp.c ft_strnew.c ft_strjoin.c ft_putstr.c ft_strcat.c \
ft_strcpy.c ft_strlen.c ft_putchar.c ft_bzero.c ft_del.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean:  clean
	/bin/rm -f $(NAME)

re: fclean all
