/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:02:06 by zkarapet          #+#    #+#             */
/*   Updated: 2022/04/20 22:05:37 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *mem, char *buf)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(sizeof(char)
			* (ft_strlen(mem) + ft_strlen(buf) + 1));
	if (!(join))
		return (NULL);
	i = 0;
	j = 0;
	if (mem)
		while (mem[i] != '\0')
			join[j++] = mem[i++];
	i = 0;
	if (buf)
		while (buf[i] != '\0')
			join[j++] = buf[i++];
	join[j] = '\0';
	free(mem);
	return (join);
}

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
