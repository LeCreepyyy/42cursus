# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 14:22:20 by vpoirot           #+#    #+#              #
#    Updated: 2023/04/21 14:24:55 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRC = ft_printf.c\
		ft_puthexa.c\
		ft_putpoint.c\
		ft_putcharnb.c

OBJ = ${SRC:.c=.o}

CC = @cc -Wall -Wextra -Werror -Iincludes -c

all: ${NAME} ${OBJ}

$(NAME): ${OBJ}
	@${MAKE} -C ./libft
	@cp libft/libft.a ${NAME}
	@ar rc ${NAME} ${OBJ}
	
clean:
	@${MAKE} clean -C ./libft
	@rm -f *.o

fclean: clean
	@${MAKE} fclean -C ./libft
	@rm -f ${NAME}

re: fclean all
