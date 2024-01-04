#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd;

	fd1 = open("docs/test.txt", O_RDONLY);
	fd2 = open("docs/test2.txt", O_RDONLY);
	fd3 = open("docs/test3.txt", O_RDONLY);
	i = 1;
	fd = 1;
	while (i < 7)
	{
		while (fd < 4)
		{
			if (fd == 1)
				line = get_next_line(fd1);
			else if (fd == 2)
				line = get_next_line(fd2);
			else if (fd == 3)
				line = get_next_line(fd3);
			printf("fd %d line [%02d]: %s", fd, i, line);
			if (!line || line[ft_strlen(line) - 1] != '\n')
				printf("\n");
			fd++;
		}
		i++;
		fd = 1;
	}
	close(fd1);
	fd1 = open("docs/test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("fd 1 line [01]: %s", line);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
