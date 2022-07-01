/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:42:59 by zkarapet          #+#    #+#             */
/*   Updated: 2022/04/21 20:39:42 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

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
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
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

char	*read_and_join(int fd, char *s)
{
	int			count;
	char		buf[BUFFER_SIZE + 1];

	count = BUFFER_SIZE;
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (NULL);
		if (count == 0 && (s == NULL || *s == '\0'))
			return (ft_free(s));
		buf[count] = '\0';
		s = ft_strjoin(s, buf);
		if (find_new_line(buf))
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*the_line;
	static char	*s[4865];

	the_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > 4864)
		return ((void *)0);
	s[fd] = read_and_join(fd, s[fd]);
	if (!s[fd])
		return (ft_free(s[fd]));
	the_line = get_line(s[fd]);
	s[fd] = get_leftover(s[fd]);
	return (the_line);
}
