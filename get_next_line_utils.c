/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:27:36 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/13 20:51:36 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_linecheck(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_ncut(char *str, int pos)
{
	char	*newstr;
	int		i;
	
	i = 0;
	if (!str)
		return (str);
	if (pos == BUFFER_SIZE)
		pos = 0;
	newstr = malloc(ft_strlen(str) - pos);
	while (ft_strlen(str) > i)
	{
		newstr[i] = str[i + pos];
		i++;
	}
	newstr[i] = '\0';
	if (str)
		free(str);
	return (newstr);
}

char	*ft_join(char *s1, char *s2, int start, int end)
{
	char	*point;
	int		i;

	if (!s2)
		return (s1);
	point = malloc(ft_strlen(s1) + end - start + 1);
	point[ft_strlen(s1) + end - start] = '\0';
	if (!point)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			point[i] = s1[i];
			i++;
		}
	}
	while (s2[start] && start <= end)
	{
		point[i + start] = s2[start];
		start++;
	}
	if (s1)
		free(s1);
	return (point);
}