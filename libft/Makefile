# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 18:55:45 by pbiederm          #+#    #+#              #
#    Updated: 2022/05/26 13:37:30 by pbiederm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCFILES := ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strcmp.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strlcat.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_strtrim.c \
ft_putnbr_fd.c
B_SRC := ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c
CC = gcc
CFLAGS = -Wextra -Werror -Wall
DEPS = libft.h
OBJS := $(SRCFILES:.c=.o) $(DEPS)
B_OBJS := $(B_SRC:.c=.o) $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	@ar r $(NAME) $(OBJS)

bonus: $(B_OBJS) $(OBJS)
	@ar rcs $(NAME) $(B_OBJS) $(OBJS)

clean:
	rm -f *.o
fclean:	clean

	rm -f $(NAME)
	
re:		fclean all

.PHONY: clean fclean re
