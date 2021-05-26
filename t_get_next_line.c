int		get_next_line(int fd, char **line)
{
	static char	*left;
	char		buff[BUFFER_SIZE + 1];
	ssize_t		read_num;
	char		*tmp;
	char		*nl_ptr;
	int			flag;

	flag = 0;
	if ((fd < 0) || *line == NULL)
		return (-1);
	tmp = left;
	printf("%s\n", left);
	while ((read_num = read(fd, buff, BUFFER_SIZE)))
	{
		if (read_num < 0)
			return (-1);
		if (read_num < BUFFER_SIZE)
			flag = 1;
		buff[read_num] = '\0';
		tmp = ft_strjoin(tmp, buff);
		ft_memset(buff, 0, BUFFER_SIZE);
		if ((nl_ptr = ft_strchr(tmp, '\n')))
		{
			*line = ft_substr(tmp, 0, nl_ptr - tmp);
			left= ft_substr(tmp, nl_ptr - tmp + 1, ft_strlen(tmp) - (nl_ptr - tmp) - 1);
			free(tmp);
			return (1);
		}
		else if (!nl_ptr && flag == 1) 
		{
			*line = tmp;
			left = ft_strdup("");
			return (0);
		}
	}
	if (tmp == NULL)
	{
		*line = ft_strdup("");
		return (0); 
	}
	if ((nl_ptr = ft_strchr(tmp, '\n')))
	{
		*line = ft_substr(tmp, 0, nl_ptr - tmp);
		left = ft_substr(tmp, nl_ptr - tmp + 1, ft_strlen(tmp) - (nl_ptr - tmp) - 1);
		free(tmp);
		return (1);
	}
	*line = tmp;
	left = ft_strdup("");
	return (0);
}

