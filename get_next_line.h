/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:57:03 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/23 14:19:29 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFF_SIZE	6
#define	OPEN_MAX	6

int		get_next_line(int fd, char **line);
void	ft_strncpy(char *dst, char const *src, size_t src_len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);

#endif