/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:40:37 by zkarapet          #+#    #+#             */
/*   Updated: 2022/04/20 20:37:08 by zkarapet         ###   ########.fr       */
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
