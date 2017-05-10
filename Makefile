# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 16:55:08 by gcadiou           #+#    #+#              #
#    Updated: 2017/05/10 04:20:47 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ls.c  stock.c list_ls.c disp.c error.c disp2.c tri.c opt_R.c disp_columns.c

PATHLIB = ~/Mygit/ft_ls/Libft/

all: $(NAME)

$(NAME):
	gcc $(SRC) Libft/libft.a -I $(PATHLIB) -o $(NAME)

compillib:
	make -C $(PATHLIB) re

clean:
#	rm -f $(SRC:.c=.o)

fclean: clean
#	rm -f a.out
	rm -f $(NAME)

re: fclean all

go: re
	./a.out
