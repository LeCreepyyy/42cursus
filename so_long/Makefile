# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:11:10 by vpoirot           #+#    #+#              #
#    Updated: 2023/04/12 13:28:56 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT = ./libft/libft.a

NAME = so_long.a

SRC = so_long.c

OBJ = ${SRC:.c=.o}

CC = cc -Wall -Wextra -Werror -fsanitize=address -g

all: ${NAME} ${OBJ}

$(NAME): ${OBJ}
	@${MAKE} -C ./libft
	@cp libft/libft.a ${NAME}
	@ar rc ${NAME} ${OBJ}
	@${CC} so_long.c *.h ${LIBFT} -o so_long
	@printf "\x1b[32mFinish !\n"

clean:
	@${MAKE} clean -C ./libft
	@rm -f *.o

fclean: clean
	@${MAKE} fclean -C ./libft
	@rm -f ${NAME}
	@rm -f server
	@rm -f client
	@printf "\x1b[31mDelete files !\n"

re: fclean all