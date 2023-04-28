# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:11:10 by vpoirot           #+#    #+#              #
#    Updated: 2023/04/28 12:19:27 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FT_PRINTF = ./ft_printf/libftprintf.a

NAME = so_long.a

SRC = so_long.c\
		set_map_tab.c\
		so_long_utils.c\
		check_map.c\
		check_map_utils.c\
		create_map.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = @cc ${CFLAGS}

all: ${NAME} ${OBJ}

$(NAME): ${OBJ}
	@printf "\x1b[33mLoading\r"
	@${MAKE} -C ./ft_printf
	@cp ft_printf/libftprintf.a ${NAME}
	@ar rc ${NAME} ${OBJ}
	@${CC} ${SRC} ${FT_PRINTF} MLX42/build/libmlx42.a -Iinclude -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/" -o so_long
	@printf "\x1b[32mFinish !\n"

clean:
	@${MAKE} clean -C ./ft_printf
	@rm -f *.o

fclean: clean
	@${MAKE} fclean -C ./ft_printf
	@rm -f ${NAME}
	@rm -f so_long
	@printf "\x1b[31mDelete files !\n"

re: fclean all
