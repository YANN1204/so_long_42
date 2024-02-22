# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:09:09 by yrio              #+#    #+#              #
#    Updated: 2024/01/30 09:18:31 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror -g3
MINILIBX_FLAGS	= -lX11 -lXext
ARCHIVE = minilibx-linux/libmlx_Linux.a
ARCHIVE_LIBFT = libft/libft.a
SRC = main.c ft_printf.c ft_printf_utils.c get_next_line.c \
	get_next_line_utils.c map_utils.c flood_fill_utils.c check_map_utils.c \
	parsing_map.c hook_utils.c graphic_utils.c movement_player.c map_utils2.c \
	get_next_line_utils2.c

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(MINILIBX_FLAGS) -o $(NAME) $(OBJ) $(ARCHIVE) $(ARCHIVE_LIBFT) -lm


$(OBJ): $(SRC)
	make -C minilibx-linux
	make -C libft
	cc $(FLAGS) -g -c $(SRC)

clean:
	make clean -C minilibx-linux
	make clean -C libft
	rm -f prog *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all