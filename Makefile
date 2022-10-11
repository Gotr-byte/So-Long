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
			map_reader.c \
			map_checker.c \
			map_checker_ii.c \
			map_checker_iii.c \
			get_next_line.c \
			get_next_line_utils.c \
			liberator.c \
			check_path.c \
			character_find.c \
			hooking.c \
			hooking_utils.c \
			img_load.c \
			img_load_utils.c \
			loop_hooking.c \
			ft_printf.c \
			ft_itoa_xx.c \
			ft_itoa_x.c \
			ft_itoa_lu.c \
			ft_putstr_i.c \
			adr_hex.c \
			ft_putchar_i.c \
			flag.c

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