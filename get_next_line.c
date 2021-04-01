/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:46:59 by mboy              #+#    #+#             */
/*   Updated: 2021/04/01 11:42:34 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_backslash(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	if (s[i] == '\n')
		return (1);
	return (0);
}

int	ft_read_buffer(int fd, char *buf)
{
	int		ret;

	ret = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (-1);
	buf[ret] = '\0';
	return (ret);
}

char	*ft_treat_save(char *save, char *buf)
{
	char	*tmp;

	if (save == NULL)
		save = ft_strdup(buf);
	else
	{
		tmp = ft_strdup(save);
		free (save);
		save = ft_strjoin(tmp, buf);
		free (tmp);
	}
	return (save);
}

char	*ft_treat_tmp(char *save)
{
	char	*tmp;

	tmp = ft_strdup(save);
	free (save);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*save;

	ret = 1;
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while (ret > 0)
	{
		ret = ft_read_buffer(fd, buf);
		if (ret == -1)
			return (-1);
		save = ft_treat_save(save, buf);
		if (ft_backslash(save) == 1)
		{
			tmp = ft_treat_tmp(save);
			*line = ft_strcut_front(tmp);
			save = ft_strcut_back(tmp);
			return (1);
		}
	}
	*line = save;
	save = NULL;
	return (0);
}
