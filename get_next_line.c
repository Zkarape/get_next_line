/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:26:26 by zkarapet          #+#    #+#             */
/*   Updated: 2022/04/21 20:37:00 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	find_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

char	*get_line(char *s)
{
	int		i;
	char	*the_line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	the_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!the_line)
		return ((void *)0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		the_line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		the_line[i] = '\n';
		i++;
	}
	the_line[i] = '\0';
	return (the_line);
}

char	*get_leftover(char *s)
{
	int		i;
	char	*new;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new = (char *)malloc(sizeof(*new) * (ft_strlen(s) - i + 1));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[j] = s[i];
		j++;
		i++;
	}
	free(s);
	new[j] = '\0';
	return (new);
}

char	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*the_line;
	static char	*s = NULL;
	int			count;

	the_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *)0);
	count = BUFFER_SIZE;
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (ft_free(s));
		if (count == 0 && (s == NULL || *s == '\0'))
			return (ft_free(s));
		buf[count] = '\0';
		s = ft_strjoin(s, buf);
		if (find_new_line(buf))
			break ;
	}
	the_line = get_line(s);
	s = get_leftover(s);
	return (the_line);
}
