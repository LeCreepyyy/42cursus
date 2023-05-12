# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:11:10 by vpoirot           #+#    #+#              #
#    Updated: 2023/05/12 11:18:42 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = push_swap.c\
		checking_arg.c\
		push_swap_utils.c\
		create_stack.c\
		move.c\
		double_move.c\
		sorted.c\
		sorted_utils.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = @cc ${CFLAGS}

all: ${NAME} ${OBJ}

$(NAME): ${OBJ}
	@printf "\x1b[33mLoading\r"
	@ar rc ${NAME} ${OBJ}
	@${CC} ${SRC} -o push_swap
	@printf "\x1b[32mFinish !\n"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}
	@rm -f push_swap
	@printf "\x1b[31mDelete files !\n"

re: fclean all