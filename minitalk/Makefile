# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 13:51:56 by vpoirot           #+#    #+#              #
#    Updated: 2023/04/04 15:12:38 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = minitalk.a

SRC = client.c\
		server.c

OBJ = ${SRC:.c=.o}

CC = cc -Wall -Wextra -Werror -fsanitize=address -g

all: ${NAME} ${OBJ}

$(NAME): ${OBJ}
	@${MAKE} -C ./libft
	@cp libft/libft.a ${NAME}
	@ar rc ${NAME} ${OBJ}
	@${CC} server.c ${LIBFT} -o server
	@${CC} client.c ${LIBFT} -o client
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
