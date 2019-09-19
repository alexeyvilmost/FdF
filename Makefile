# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 15:21:19 by pallspic          #+#    #+#              #
#    Updated: 2019/09/19 18:56:57 by pallspic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#defending pseudo-rules from unexpected similiar-name files if directory
#
#Защита псевдоправил от случайного поведения, когда файлы с такими именами уже
#существуют в директории

.PHONY: all re clean fclean libft

CFLAGS = -Wall -Werror -Wextra -Iincludes

LIB_MAKE = make -C $(LIB_DIR)

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

NAME = fdf

SRC = 	main.c \
		input.c \
		coor.c \
		draw.c \
		keys.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(CFLAGS) $(SRC) -L libft/ -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libft:
	$(LIB_MAKE)

%.a:
	$(LIB_MAKE)

obj/%.o: %.c
	gcc -c $(CFLAGS) $<

fclean: clean
	rm -rf $(NAME)
	$(LIB_MAKE) fclean

clean:
	rm -rf $(OBJ)
	$(LIB_MAKE) clean

re: fclean all
