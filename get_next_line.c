/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:22:19 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/11 16:27:50 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*result;
	char		buff[BUFFER_SIZE + 1];
	int			n;

	result = "";
	n = 0;
	result = ft_join(result, rem, 0, ft_linecheck(rem));
	rem = ft_ncut(rem);
	buff[BUFFER_SIZE] = '\0';
	while (!n || n == BUFFER_SIZE)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
			break ;
		n = ft_linecheck(buff);
		result = ft_join(result, buff, 0, n);
	}
	if (n == BUFFER_SIZE)
		n = 0;
	rem = ft_join(rem, buff, ft_linecheck(buff) + 1, BUFFER_SIZE);
	return (result);
}