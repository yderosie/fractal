# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 12:52:10 by yderosie          #+#    #+#              #
#    Updated: 2014/12/14 15:58:26 by yderosie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/opt/X11/include/
FLAGSMLX = -L/usr/X11/lib -lmlx -lXext -lX11

FILES = 	fract_ol	\
			hook		\
			fractal	

SRCS	= $(addsuffix .c, $(FILES))
OBJ		= $(SRCS:%.c=obj/%.o)

.PHONY: all clean fclean re dirobj
.SILENT: dirobj clean fclean re all $(NAME)

all: dirobj $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(FLAGSMLX) -I./ -o $(NAME) $(OBJ) libft/libft.a

obj/%.o: %.c
	@$(CC) $(CFLAGS) $(FLAGSMLX) -I./ -o $@ -c $^

clean:
	test ! -d obj || \
		rm -rf obj

fclean: clean
	test ! -f $(NAME) || \
		rm -f $(NAME)

re: fclean all

dirobj:
	test -d obj || \
		mkdir -p obj

