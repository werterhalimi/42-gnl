/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:20:34 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/23 19:37:24 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
void	*ft_calloc(size_t nb, size_t len);
char	*ft_strdup(const char *s);
char	*ft_addchar(char *src, char c);
char	*ft_strfix(char *src);
char	*get_next_line(int fd);
#endif
