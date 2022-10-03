# so_long.c \
# get_next_line.c \
# get_next_line_utils.c \
# hooking.c

define IMG

░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░▄ ▀▄▄▀▄░░░░░░░░░░░░░░░░░░░░░▄ ▀▄▄▀▄░░░░░░░░░░░░░░░░░░░░░▄ ▀▄▄▀▄░░░░░░░░░░░░░░
░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░░░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░░░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░
░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░░░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░░░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░
░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░░░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░░░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░
░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░░░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░░░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░
░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░
░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░
░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░░░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░░░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░
░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░░░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░░░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░
*Barf*

endef
export IMG

NAME := so_long
LIBFT_DIR = libft/
LIBFT_EXEC = ./libft/libft.a
SRCFILES := so_long.c \
			get_next_line.c \
			get_next_line_utils.c \
			hooking.c

CC = gcc
CFLAGS = -Wextra -Werror -Wall
OBJS := $(SRCFILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@make bonus -C libft/ 
	$(CC) -g $(CFLAGS) $(SRCFILES) $(LIBFT_EXEC) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo $(GREEN) "$$IMG"
clean:
	# rm -f *.o
	rm -f $(OBJS)
	make clean -C libft/
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft/
	
re:		fclean all

CROSS = "\033[8m"
RED = "\033[0;1;91m"
GREEN = "\033[0;1;32m"
BLUE = "\033[0;1;34m"

.PHONY: clean fclean re