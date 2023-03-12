/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:19 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/12 21:07:57 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*result;
	char		buff[BUFFER_SIZE + 1];
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	result = calloc(1,1);
	n = 0;
	result = ft_join(result, rem, 0, ft_linecheck(rem));
	//printf("%d \n", __LINE__);
	rem = ft_ncut(rem, ft_linecheck(rem));
	//printf("%d \n", __LINE__);
	buff[BUFFER_SIZE] = '\0';
	while (!n)
	{
		n = read(fd, buff, BUFFER_SIZE);
		//printf("%d \n", __LINE__);
		if (n <= 0 || result == NULL)
			return (NULL);
		n = ft_linecheck(buff);
		//printf("%s - buf; %d - n\n\n", buff, n);
		result = ft_join(result, buff, 0, n);
		if (n == 0)
			break;
		if (n == BUFFER_SIZE)
			n = 0;
		//printf("%s - loop res , %d - n\n", result, n);
	}
	//printf("%s - buff\n", buff);
	rem = ft_join(rem, buff, ft_linecheck(buff), BUFFER_SIZE);
	//printf("%d \n", __LINE__);
	return (result);
}

// int main()
// {
// 	int fd;

// 	fd = open("test.txt", O_RDONLY | O_RDWR);
// 	printf("%s", get_next_line(fd));
// }