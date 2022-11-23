/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:22:05 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/23 19:37:36 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	buffer_map(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

int	ft_create_buffer(int *i, char **buffer, int *len, int fd)
{
	*i = 0;
	if (!*buffer)
	{
		*buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		*len = read(fd, *buffer, BUFFER_SIZE);
		if (*len <= 0)
		{
			free(*buffer);
			*buffer = 0;
			return (1);
		}
		(*buffer)[*len] = 0;
	}
	else
		*len = ft_strlen(*buffer);
	return (0);
}

int	ft_read_buffer(int *i, int len, char **ret, char **buffer)
{
	int	j;

	j = 0;
	while (j < len)
	{
		*ret = ft_addchar(*ret, (*buffer)[j]);
		if ((*ret)[*i] == '\n')
		{
			buffer_map(*buffer, &((*buffer)[j + 1]));
			if (!ft_strlen(*buffer))
			{
				free(*buffer);
				*buffer = 0;
			}
			return (1);
		}
		j++;
		(*i)++;
	}
	return (0);
}

char	*ft_process_buffer(char **ret, char **buffer, int *len)
{
	if (*len <= 0)
	{
		free(*buffer);
		*buffer = 0;
		if (*ret)
			return (ft_strfix(*ret));
		return (*buffer);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*ret;
	int			len;
	int			i;
	char		*j;

	if (fd < 0 || ft_create_buffer(&i, &(buffer[fd]), &len, fd))
		return (0);
	ret = ft_calloc(sizeof(char), len + 1);
	while (ret[i] != '\n')
	{
		if (ft_read_buffer(&i, len, &ret, &(buffer[fd])))
			return (ft_strfix(ret));
		if (ret[i] != '\n')
		{
			len = read(fd, buffer[fd], BUFFER_SIZE);
			if (len >= 0)
				(buffer[fd])[len] = 0;
		}
		j = ft_process_buffer(&ret, &(buffer[fd]), &len);
		if (j)
			return (j);
	}
	ret[i] = 0;
	return (ft_strfix(ret));
}
