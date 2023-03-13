NAME = password

all: passwordgen.o
	@gcc passwordgen.o -o ${NAME}

passwordgen.o: passwordgen.c
	@gcc -Wall -Wextra -Werror -c passwordgen.c -o passwordgen.o
	@printf "\x1b[32mFinish !\n"
clean:
	@rm -rf *.o password
	@printf "\x1b[31mRepository is clean !\n"
re: clean all
