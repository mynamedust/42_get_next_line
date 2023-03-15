/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:19 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/15 22:38:29 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:10:50 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/15 22:01:03 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*rem;
	char		buff[BUFFER_SIZE + 1];
	char		result;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	n = 1;
	result = NULL;
	if (rem)
	{
		result = ft_join(result, rem);
		rem = ft_ncut(rem);
		if (ft_strchr(result, '\n'))
			return (result);
	}
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
			return (result);
		buff[n] = '\0';
		result = ft_join(result, buff);
		if ((n = ft_strchr(buff, '\n')) >= 0)
			break;
	}
	if (n == BUFFER_SIZE)
		return (result);
	rem = ft_remadd(rem, buff);
	return (result);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	char	*res;

	if (!s2)
		return (s1);
	if ((i = ft_strchr(s2)) < 0)
		i = BUFFER_SIZE - 1;
	res = malloc(ft_strlen(s1) + i + 2);
	res[ft_strlen(s1) + i + 2] = '\0';
	i = 0;
	if (s1)
	{
		while (s1[i++])
			res[i - 1] = s1[i - 1];
	}
	i = 0;
	while (s2[i++])
	{
		res[ft_strlen(s1) + i - 1] = s2[i - 1];
		if (s2[i - 1] == '\n')
			break;
	}
	if (s1)
		free(s1);
	return (res);
}