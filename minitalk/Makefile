# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 13:51:56 by vpoirot           #+#    #+#              #
#    Updated: 2023/03/27 13:59:31 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ./ft_printf/libftprintf.a

NAME = minitalk.a

SRC = client.c\
		server.c

OBJ = ${SRC:.c=.o}

CC = cc -Wall -Wextra -Werror -fsanitize=address -g

all: ${NAME} ${OBJ}

$(NAME): ${OBJ}
	@${MAKE} -C ./ft_printf
	@cp ft_printf/libftprintf.a ${NAME}
	@ar rc ${NAME} ${OBJ}
	@${CC} server.c ${FT_PRINTF} -o server
	@${CC} client.c ${FT_PRINTF} -o client
	@printf "\x1b[32mFinish !\n"
	
clean:
	@${MAKE} clean -C ./ft_printf
	@rm -f *.o

fclean: clean
	@${MAKE} fclean -C ./ft_printf
	@rm -f ${NAME}
	@printf "\x1b[31mDelete files !\n"

re: fclean all
