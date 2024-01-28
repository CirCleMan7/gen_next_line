#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s)
{
	int             count;
	char    *str;

	str = (char *)s;
	count = 0;
	while (*str)
	{
			str++;
			count++;
	}
	return (count);
}

size_t  ft_strlcat(char *dest, char *src, size_t amount)
{
	size_t  len;

	len = ft_strlen(dest) + ft_strlen(src);
	if (amount <= ft_strlen(dest))
			return (ft_strlen(src) + amount);
	while (*dest)
	{
			dest++;
			amount--;
	}
	while (amount-- - 1 && *src)
	{
			*dest = *src;
			dest++;
			src++;
	}
	*dest = 0;
	return (len);
}

size_t  ft_strlcpy(char *dest, char *src, size_t amount)
{
	size_t  lensrc;

	lensrc = ft_strlen(src);
	while (amount - 1 && amount > 0 && *src)
	{
			*dest = *src;
			dest++;
			src++;
			amount--;
	}
	if (amount > 0)
		*dest = 0;
	return (lensrc);
}

int	check_newline(char  *str)
{
	int	check;

	check = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			check = 1;
			break;
		}
		str++;
	}
	return (check);
}

char	*return_str(char *str)
{
	char	*collect;
	char	*buffer;
	int		i;
	int		j;

	collect = malloc(100);
	buffer = malloc(100);
	i = 0;
	j = 0;
	while (*(str + i) != '\n' && *(str + i))
	{
		*(collect + i) = *(str + i);
		// printf("%c\n", *(str + i));
		i++;
	}
	*(collect + i++) = '\n';
	ft_strlcpy(buffer, (str + i), ft_strlen(str + i) + 1);
	ft_strlcpy(str, buffer, ft_strlen(buffer) + 1);
	// printf("str = %s\n", str);
	return (collect);
}

char	*gen_next_line(int fd)
{
	static char *str;
	char *buffer;
	char *answer;
	int i;

	i = 1;
	answer = malloc(100);
	buffer = malloc(100);
	if (!str)
		str = malloc(100);
	while (i != 0)
	{
		if (check_newline(str) != 1)
		{
			i = read(fd, buffer, 42);
			// printf("%d\n", i);
			ft_strlcat(str, buffer, 1000);
		}
		if (check_newline(str) == 1)
		{
			// printf("%s", str);
			answer = return_str(str);
			break;
		}
	}
	return (answer);
}

int	main()
{
	char *str;
	int fd = open("eiei.txt", O_RDONLY);
	printf("%d\n", fd);
	str = gen_next_line(fd);
	printf("%s", str);
	str = gen_next_line(fd);
	printf("%s", str);
	str = gen_next_line(fd);
	printf("%s", str);
	str = gen_next_line(fd);
	printf("%s", str);
		str = gen_next_line(fd);
	printf("%s", str);
		str = gen_next_line(fd);
	printf("%s", str);
	str = gen_next_line(fd);
	printf("%s", str);
	str = gen_next_line(fd);
	printf("%s", str);
	str = gen_next_line(fd);
	printf("%s", str);
	// ft_strlcat("Hello", "World", 10);
	// printf("%d", check_newline("Hel\nlo"));
	
}
