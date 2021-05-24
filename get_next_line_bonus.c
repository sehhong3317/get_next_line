/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:20:07 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/23 20:42:25 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		nl_locater(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static int		line_assigner(int nl_idx, char **left, char **line)
{
	char *tmp;

	(*left)[nl_idx] = '\0';
	*line = ft_strdup(*left);
	tmp = ft_strdup(*left + nl_idx + 1);
	free(*left);
	*left = tmp;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	ssize_t			read_num;
	char			buff[BUFFER_SIZE + 1];
	static char		*left[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while ((read_num = read(fd, buff, BUFFER_SIZE)))
	{
		buff[read_num] = '\0';
		left[fd] = ft_strjoin(left[fd], buff);
		if (ft_strchr(left[fd], '\n'))
			return (line_assigner(nl_locater(left[fd]), &left[fd], line));
	}
	if (ft_strchr(left[fd], '\n'))
		return (line_assigner(nl_locater(left[fd]), &left[fd], line));
	if (left[fd] == NULL)
		*line = ft_strdup("");
	else
		*line = left[fd];
	left[fd] = NULL;
	return (0);
}
