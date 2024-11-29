/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:44:40 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/29 00:52:47 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*concat_buffers_with_strjoin(char *position, char *buff)
{
	char	*new_position;

	if (!position)
	{
		return (ft_strdup(buff));
	}
	new_position = ft_strjoin(position, buff);
	free(position);
	return (new_position);
}

static char	*read_line(int fd, char *position)
{
	ssize_t	nbyt_read;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(position, '\n'))
	{
		nbyt_read = read(fd, buff, BUFFER_SIZE);
		if (nbyt_read < 0)
		{
			return (free(buff), free(position), NULL);
		}
		if (nbyt_read == 0)
			break ;
		buff[nbyt_read] = '\0';
		position = concat_buffers_with_strjoin(position, buff);
		if (!position)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (position);
}

static char	*extract_line(char *position)
{
	char	*line;
	size_t	i;

	if (!position || !*position)
	{
		return (NULL);
	}
	i = 0;
	while (position[i] && position[i] != '\n')
	{
		i++;
	}
	line = malloc(i + (position[i] == '\n') + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, position, i + (position[i] == '\n'));
	line[i + (position[i] == '\n')] = '\0';
	return (line);
}

static char	*clean_position(char *position)
{
	size_t	i;
	size_t	len;
	char	*new_position;

	i = 0;
	while (position[i] && position[i] != '\n')
		i++;
	if (!position[i])
	{
		free(position);
		return (NULL);
	}
	len = ft_strlen(position) - i - 1;
	new_position = malloc(len + 1);
	if (!new_position)
	{
		free(position);
		return (NULL);
	}
	ft_memcpy(new_position, position + i + 1, len);
	new_position[len] = '\0';
	free(position);
	return (new_position);
}

char	*get_next_line(int fd)
{
	static char	*positions[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	positions[fd] = read_line(fd, positions[fd]);
	if (!positions[fd])
		return (NULL);
	line = extract_line(positions[fd]);
	positions[fd] = clean_position(positions[fd]);
	return (line);
}