#include "get_next_line.h"

char	*empty_string(void)
{
	char	*s1;

	s1 = malloc(1);
	if (s1 == NULL)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

size_t	ft_strlen(const char *string)
{
	const char	*iterator;

	iterator = string;
	while (*iterator)
	{
		iterator++;
	}
	return (iterator - string);
}

char	*ft_strchr(const char *str, int c)
{
	const char	*temp;

	if (!str)
		return (NULL);
	temp = str;
	while (*temp)
	{
		if (*temp == (char) c)
			return ((char *) temp);
		temp++;
	}
	if ((char) c == '\0')
		return ((char *) temp);
	return (NULL);
}

char	*ft_strjoin(char *stack, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stack || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(stack) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (stack[i] != '\0')
	{
		str[i] = stack[i];
		i++;
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(stack) + ft_strlen(buff)] = '\0';
	free(stack);
	return (str);
}
