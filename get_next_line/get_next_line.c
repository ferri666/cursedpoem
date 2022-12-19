/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:39:18 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/03 18:37:34 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 2));
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = 0;
	free(buffer);
	return (new_buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*read_file(int fd, char *original_buff)
{
	char	*buffer;
	int		byte_read;

	if (!original_buff)
		original_buff = ft_calloc(1, 1);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		original_buff = ft_free(original_buff, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (original_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free(buff);
		buff = 0;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_line(buff);
	buff = ft_next(buff);
	return (line);
}
