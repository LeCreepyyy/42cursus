# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 14:22:20 by vpoirot           #+#    #+#              #
#    Updated: 2023/06/15 14:06:20 by vpoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_putstr_fd.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_strdup.c\
		ft_calloc.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_striteri.c\
		ft_strmapi.c\
		ft_itoa.c\
		ft_split.c

SRC_BNS = ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJ = ${SRC:.c=.o}

OBJ_BNS = ${SRC_BNS:.c=.o}

CC = @cc -Wall -Wextra -Werror

$(NAME): ${SRC} ${OBJ}
	@ar rc ${NAME} ${OBJ}
	@printf "\x1b[32mLibrary Compiled !\n"

all: ${NAME}

bonus: ${NAME} ${OBJ_BNS}
	@ar rc ${NAME} ${OBJ_BNS}

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}
	@printf "\x1b[31mFile delete !\n"

re: fclean all
