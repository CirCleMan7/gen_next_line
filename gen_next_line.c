#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*gen_next_line(int fd)
{
	static char *buffer;
	char *line;
	static char *collectline;
	int i;
	int j;

	i = 0;
	j = 0;
	buffer = malloc(100);
	line = malloc(100);
	collectline = malloc(100);
	read(fd, buffer, 20);

	while (buffer[i] != 10)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i++] = 10;
	while (buffer[i] != 0)
	{
		collectline[j] = buffer[i];
		i++;
		j++;
	}
	printf("collectline = %s\n", collectline);
	return (line);
}

int	main()
{
	int fd = open("eiei.txt", O_RDONLY);
	char *str;

	str = gen_next_line(fd);
	printf("%s", str);
/*	while (*buffer != 10)
	{
		read(fd, buffer, 10);
		printf("%s", buffer);
	}*/

}
