/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:01:06 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/23 15:15:42 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	*ft_calloc(size_t nb, size_t len)
{
	void	*ret;
	int		i;

	i = 0;
	ret = malloc(len * nb);
	if (!ret)
		return (0);
	while (i < (int)(len * nb))
		((unsigned char *)ret)[i++] = 0;
	return (ret);
}

char	*ft_addchar(char *src, char c)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(src) + 1;
	ret = malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len - 1)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = c;
	ret[len] = 0;
	free(src);
	return (ret);
}

char	*ft_strfix(char *src)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(src);
	ret = malloc (sizeof(char) * len + 1);
	i = 0;
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	free(src);
	return (ret);
}
