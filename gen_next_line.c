#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int		count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
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

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *start;
	char    *answer;

	answer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!answer)
		return (NULL);
	start = answer;
	while (*s1)
	{
		*answer = *s1;
		s1++;
		answer++;
	}
	while (*s2)
	{
		*answer = *s2;
		s2++;
		answer++;
	}
	*answer = '\0';
	return (start);
}

int	check_newline(char  *str)
{
	int	check;

	check = 0;
	if (str == 0)
		return (0);
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

int len_font(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len += 1;
		if (*str == '\n')
			break;
		str++;
	}
	return (len);
}

char	*return_str(char *str)
{
	char	*collect;
	char	*buffer;
	int		i;
	int		j;

	collect = malloc(sizeof(char) * (len_font(str) + 1));
	// printf("%lu\n", (ft_strlen(str) - ft_strlen(collect) + 1));
	i = 0;
	j = 0;
	while (*(str + i) != '\n' && *(str + i))
	{
		*(collect + i) = *(str + i);
		// printf("%c", *(collect + i));
		// printf("%c\n", *(str + i));
		i++;
	}
	// printf("\n");
	*(collect + i++) = '\n';
	*(collect + i) = '\0';
	buffer = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(collect) + 1));
	ft_strlcpy(buffer, (str + i), ft_strlen(str + i) + 1);
	free(str);
	str = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ft_strlcpy(str, buffer, ft_strlen(buffer) + 1);
	free(buffer);
	// printf("collect = %s\n", collect);
	return (collect);
}

void	joinStr(char **str, char *buffer)
{
	char	*temp;

	printf("ei");
	// ft_strlcpy(temp, str);
	// printf("buffer = %s\n", buffer);
	**str = 0;
	temp = ft_strjoin(*str, buffer);
	// printf("temp = %s\n", temp);
	// if (str)
	// printf("*str = %p\n", *str);
	// if ((*str) != NULL)
		// free(*str);
	// free(buffer);
	// *str = temp;
	// printf("str = %s\n", *str);
	// printf("str = %s\n", *str);
}

char	*gen_next_line(int fd)
{
	static char *str;
	char *buffer;
	char *answer;
	int BUFFER_SIZE;
	int i;

	i = 1;
	BUFFER_SIZE = 2;
	buffer = malloc(BUFFER_SIZE + 1);

	while (i != 0)
	{
		if (check_newline(str) != 1)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			buffer[i] = '\0';
			printf("buffer = %s\n", buffer);
			// printf("e");
			// printf("buffer = %s\n", buffer);
			printf("a\n");
			joinStr(&str, buffer);
		}
		// printf("str .. = %s\n", str);
		if (check_newline(str) == 1)
		{
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
	// printf("%s", str);
	// str = gen_next_line(fd);
	// printf("%s", str);
	// str = gen_next_line(fd);
	// printf("%s", str);
	// free(str);
	// ft_strlcat("Hello", "World", 10);
	// printf("%d", check_newline("Hel\nlo"));
	
}
