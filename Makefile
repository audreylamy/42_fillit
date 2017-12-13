# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 18:07:22 by lesanche          #+#    #+#              #
#    Updated: 2017/12/12 14:33:21 by lesanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRC = main.c check.c create.c tab_tetri_top_left.c map.c resolution.c ft_sqrt_fillit.c

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

%.o:    %.c
	$(CC) $(CFLAGS) -c $<

$(LIBFT):
	make -C $(LIBFT_DIR)

clean : 
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: all clean fclean re
