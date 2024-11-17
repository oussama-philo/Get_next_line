
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*---------------includes---------------*/

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*---------------BUFFER_SIZE---------------*/

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

/*---------------Fun Utils---------------*/

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
