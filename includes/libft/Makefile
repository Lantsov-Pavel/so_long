# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 15:01:38 by plantsov          #+#    #+#              #
#    Updated: 2024/12/12 15:01:48 by plantsov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_memchr.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
       ft_isalpha.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_toupper.c \
       ft_isascii.c ft_memcpy.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_atoi.c \
       ft_isdigit.c ft_memmove.c ft_strchr.c ft_strlen.c ft_substr.c ft_tolower.c \
       ft_bzero.c ft_isprint.c ft_memset.c ft_strdup.c ft_strmapi.c ft_calloc.c \
       ft_itoa.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_isalnum.c ft_putchar_fd.c \
       libftprintf/ft_print_chr.c libftprintf/ft_print_ptr.c libftprintf/ft_print_nbr.c libftprintf/ft_print_hex.c\
       libftprintf/ft_print_str.c libftprintf/ft_printf.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re