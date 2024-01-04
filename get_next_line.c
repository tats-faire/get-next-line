#include "get_next_line.h"

// remove first line from stack and return remaining content
char	*free_returned_line(char *stack)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		str[j++] = stack[i++];
	str[j] = '\0';
	free(stack);
	return (str);
}

// return first line from stack
char	*ft_get_new_line(char *stack)
{
	int		i;
	char	*str;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		str[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		str[i] = stack[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// read from fd and stash in stack until newline is found
char	*stash_new_line(int fd, char *stack)
{
	int		bytes_read;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stack, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		if (bytes_read != 0)
			stack = ft_strjoin(stack, buff);
	}
	free(buff);
	return (stack);
}

// read from a fd and return first line
char	*get_next_line(int fd)
{
	static char	*stack[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stack[fd])
		{
			free(stack[fd]);
			stack[fd] = NULL;
		}
		return (NULL);
	}
	if (!stack[fd])
		stack[fd] = empty_string();
	if (!stack[fd])
		return (NULL);
	stack[fd] = stash_new_line(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	result = ft_get_new_line(stack[fd]);
	stack[fd] = free_returned_line(stack[fd]);
	return (result);
}
