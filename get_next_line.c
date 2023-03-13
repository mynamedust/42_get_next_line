/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:19 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/13 21:10:37 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*result;
	char		*buff;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	result = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	n = 0;
	result = ft_join(result, rem, 0, ft_linecheck(rem));
	rem = ft_ncut(rem, ft_linecheck(rem));
	buff[BUFFER_SIZE] = '\0';
	while ((read(fd, buff, BUFFER_SIZE)) > 0)
	{
		n = ft_linecheck(buff);
		result = ft_join(result, buff, 0, n);
		if (n > 0 && n != BUFFER_SIZE)
			break;
	}
	rem = ft_join(rem, buff, ft_linecheck(buff), BUFFER_SIZE);
	if (buff)
		free(buff);
	return (result);
}

// int main()
// {
// 	int fd;

// 	fd = open("test.txt", O_RDONLY | O_RDWR);
// 	printf("%s - end of programm\n", get_next_line(fd));
// }