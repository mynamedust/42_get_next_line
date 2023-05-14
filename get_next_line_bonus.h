/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:16:13 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/18 19:16:37 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include<fcntl.h>
# include<limits.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *stc);
char	*ft_newline(char *stc);
char	*ft_ncut(char *stc);
char	*ft_join(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *str);
char	*ft_stcjoin(char *stc, char *buff);
#endif