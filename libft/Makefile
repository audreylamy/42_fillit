# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 14:31:55 by lesanche          #+#    #+#              #
#    Updated: 2017/12/12 14:32:21 by lesanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strcmp.c ft_atoi.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
ft_toupper.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putendl.c ft_putnbr.c ft_putstr.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsub.c ft_strtrim.c ft_strsplit.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_swap.c ft_abs.c ft_negative.c \
ft_putnbrendl.c ft_strrev.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:    %.c
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
