#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*stash_new_line(int fd, char *stack);
char	*ft_get_new_line(char *stack);
char	*free_returned_line(char *stack);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *stack, char *buff);
char	*empty_string(void);

#endif
