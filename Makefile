# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 18:09:31 by ebaudet           #+#    #+#              #
#    Updated: 2013/12/22 18:09:31 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRCS	= main.c\
		  get_data.c\
		  calc.c\
		  draw.c
OBJS	= ${SRCS:.c=.o}
INC		= ./
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) $(SRCS) -o $(NAME) -I libft/includes -L libft/ -lft \
	-L /usr/X11/lib -lmlx -lXext -lX11

%.o: %.c
	gcc -c $< -o $@ $(FLAGS) -I$(INC)

gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) -I libft/includes -L libft/ -lft \
	-L /usr/X11/lib -lmlx -lXext -lX11
	gdb $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean re
