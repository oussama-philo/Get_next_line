
#include "get_next_line.h"

static char *concatenate_strs(char *res, char *Buff)
{
	char *tmp;
	tmp = ft_strjoin(res, Buff);
	if (!tmp)
		return NULL;
	free(Buff);
	free(res);
	return (tmp);
}

static char *ft_read_file(int fd, char *res)
{
	char *Buff;
	ssize_t nbyt_read;

	if (!res)
	{
		res = ft_calloc(1, 1);
	}
	Buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!Buff)
	{
		free(res);
		return (NULL);
	}
	nbyt_read = read(fd, Buff, BUFFER_SIZE);
	if (nbyt_read < 0)
	{
		free(Buff);
		free(res);
		return (NULL);
	}
	Buff[nbyt_read] = '\0';
	res = concatenate_strs(res, Buff);
	return (res);
}

static char *ft_get_New_line(char **remainder)
{
	char *newline_pos;
	char *line;
	char *new_remainder;

	newline_pos = ft_strchr(*remainder, '\n');
	if (!newline_pos)
		return NULL;

	line = ft_substr(*remainder, 0, newline_pos - *remainder + 1);
	if (!line)
		return NULL;

	new_remainder = ft_strdup(newline_pos + 1);
	free(*remainder);
	*remainder = new_remainder;

	return line;
}

char *get_next_line(int fd)
{
	static char *remainder;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return 0;
	}
	remainder = ft_read_file(fd, remainder);
	if (!remainder || !*remainder)
	{
		if (remainder)
			free(remainder);
		remainder = NULL;
		return NULL;
	}
	line = ft_get_New_line(&remainder);
	return (line);
}

