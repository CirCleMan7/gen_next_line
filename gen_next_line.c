#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main()
{
	static char *buffer;
	int fd = open("eiei.txt", O_RDONLY);

	buffer = malloc(100);
	read(fd, buffer, 10);
	printf("%s", buffer);
}
