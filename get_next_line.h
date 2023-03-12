/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:50:06 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/12 21:03:44 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include <stddef.h>
# include <fcntl.h>
#include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		ft_linecheck(char *str);
char	*ft_ncut(char *str, int pos);
char	*ft_join(char *s1, char *s2, int start, int end);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
#endif