/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:27:36 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/12 21:01:46 by almeliky         ###   ########.fr       */
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
	int		len;
	char	*point;

	if (!s2 || !s1)
		return (s1);
	len = ft_strlen(s1) + end - start;
	point = calloc(len + 1, 1);
	//printf("%d - len\n", len + 1);
	if (!point)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		//printf("%s voshel v s1 cikl \n", point);
		point[len] = s1[len];
		len++;
	}
	//printf("%s - after s1 \n", point);
	if (s1)
		free(s1);
	len = start;
	while (s2[start] && start < end)
	{
		point[ft_strlen(s1) + len] = s2[start];
		len++;
		start++;
	}
	//printf("%s - after s2 \n", point);
	return (point);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*point;

	i = 0;
	while (s1[i])
		i++;
	point = (char *)malloc(sizeof(char) * (i + 1));
	if (!point)
		return (NULL);
	i = 0;
	while (s1[i++])
		point[i - 1] = s1[i - 1];
	point[i - 1] = '\0';
	return (point);
}