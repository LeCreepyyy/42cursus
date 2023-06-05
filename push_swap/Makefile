# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:11:10 by vpoirot           #+#    #+#              #
#    Updated: 2023/06/05 10:15:17 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

BONUS_NAME = checker.a

SRC = push_swap.c\
		checking_arg.c\
		push_swap_utils.c\
		create_stack.c\
		move.c\
		double_move.c\
		sorted.c\
		sorted_utils.c\
		big_algo.c\
		ft_split.c\
		ft_strjoin.c\
		global_utils.c\
		get_next_line.c\
		get_next_line_utils.c\
		checker_utils.c

SRC_BNS = checker.c\
		checking_arg.c\
		push_swap_utils.c\
		create_stack.c\
		move.c\
		double_move.c\
		sorted.c\
		sorted_utils.c\
		big_algo.c\
		ft_split.c\
		ft_strjoin.c\
		global_utils.c\
		get_next_line.c\
		get_next_line_utils.c\
		checker_utils.c

OBJ = ${SRC:.c=.o}

OBJ_BNS = ${SRC_BNS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

CC = @cc ${CFLAGS}


$(NAME): ${OBJ}
	@printf "\x1b[33mLoading\r"
	@ar rc ${NAME} ${OBJ}
	@${CC} ${SRC} -o push_swap
	@printf "\x1b[32mFinish !\n"

all: ${NAME} ${OBJ}

bonus: ${OBJ_BNS}
	@printf "\x1b[33mLoading\r"
	@ar rc ${BONUS_NAME} ${OBJ_BNS}
	@${CC} ${SRC_BNS} -o checker
	@printf "\x1b[32mFinish !\n"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}
	@rm -f push_swap
	@rm -f checker
	@rm -f checker.a
	@printf "\x1b[31mDelete files !\n"

re: fclean all

re_bonus: fclean bonus
