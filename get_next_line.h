/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:07 by mboy              #+#    #+#             */
/*   Updated: 2021/04/01 11:42:38 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcut_front(char *str);
char	*ft_strcut_back(char *str);
int		get_next_line(int fd, char **line);
int		ft_backslash(const char *s);
int		ft_read_buffer(int fd, char *buf);
char	*ft_treat_save(char *save, char *buf);
char	*ft_treat_tmp(char *save);

#endif
