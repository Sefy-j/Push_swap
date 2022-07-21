/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:59 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 14:15:57 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extraline(char *text)
{
	size_t	i;
	size_t	len;
	size_t	tlen;
	char	*exline;

	i = 0;
	len = ft_linelen(text);
	if (!text[len])
	{
		free(text);
		return (NULL);
	}
	tlen = ft_strlen(text);
	exline = (char *)malloc(sizeof(char) * (tlen - len + 1));
	if (!exline)
		return (NULL);
	while (len + i < tlen)
	{
		exline[i] = text[i + len];
		i++;
	}
	exline[i] = '\0';
	free(text);
	return (exline);
}

static char	*ft_line(char *text)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	if (!text[i])
		return (NULL);
	len = ft_linelen(text);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *text)
{
	ssize_t	nb;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb = 1;
	while (!ft_strchr(text, '\n') && nb != 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb] = '\0';
		if (!text)
			text = ft_strdup(buffer);
		else
			text = ft_strjoingnl(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = ft_read(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = ft_line(text[fd]);
	text[fd] = ft_extraline(text[fd]);
	return (line);
}
