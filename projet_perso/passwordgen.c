#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	genword(int size)
{
	int	index;

	index = 0;
	srand(time(NULL));
	while (size-- > 0)
		printf("%c", 33 + rand() % 94);
	printf("\n");
}

int	main(int argc, char **argv)
{
	int	size;

	if (argc < 2)
		return (printf("No argument found !\n"));
	size = atoi(argv[1]);
	if (size < 8)
		return (printf("Password too short !\n"));
	if (size > 20)
		return (printf("Password too long !\n"));
	genword(size);
	return (size);
}
