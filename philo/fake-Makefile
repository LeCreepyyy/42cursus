# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 11:15:44 by vpoirot           #+#    #+#              #
#    Updated: 2023/06/06 13:36:22 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo.a

SRC = main.c\
		utils.c\
		routine.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -pthread

CC = @cc ${CFLAGS}

$(NAME): ${OBJ}
	@printf "\x1b[33mLoading\r"
	@ar rc ${NAME} ${OBJ}
	@${CC} ${SRC} -o philo
	@printf "\x1b[32mFinish !\n"

all: ${NAME} ${OBJ}

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}
	@rm -f philo
	@printf "\x1b[31mDelete files !\n"

re: fclean all
