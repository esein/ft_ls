# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 16:55:08 by gcadiou           #+#    #+#              #
#    Updated: 2017/06/28 18:18:09 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ls.c           \
	  stock.c        \
	  list_ls.c      \
	  disp.c         \
	  error.c        \
	  disp2.c        \
	  disp3.c        \
	  tri.c          \
	  opt_br.c       \
	  disp_columns.c \
	  stock_arg.c

OBJ = $(SRC:.c=.o)

PATHLIB = ./Libft

LIB = $(PATHLIB)/libft.a

FLAG = -Wall -Werror -Wextra

all: compillib $(NAME)

$(NAME): $(LIB) $(SRC)
	gcc $(SRC) $(LIB) -I $(PATHLIB) -o $(NAME) $(FLAG)

compillib:
	make -C $(PATHLIB)

.PHONY: compillib clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
