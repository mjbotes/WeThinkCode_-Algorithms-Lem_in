/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:32:57 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/05 16:21:45 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reader(char **fd_arr, int fd)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	while (ft_strchr(*fd_arr, '\n') == NULL)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(*fd_arr, buff);
		ft_strdel(fd_arr);
		*fd_arr = ft_strdupdel(&tmp);
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*fd_arr[255];
	char			*ptr;
	char			*tmp;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	if (fd_arr[fd] == NULL)
		fd_arr[fd] = ft_strnew(0);
	ft_reader(&fd_arr[fd], fd);
	if ((ptr = ft_replacechr(&fd_arr[fd], '\n', '\0')) != NULL)
	{
		tmp = ft_strdup(ptr + 1);
		*line = ft_strdupdel(&fd_arr[fd]);
		ft_strdel(&fd_arr[fd]);
		if (tmp != NULL)
			fd_arr[fd] = ft_strdupdel(&tmp);
		return (1);
	}
	if (ft_strlen(fd_arr[fd]) == 0)
		return (0);
	if (ft_strlen(fd_arr[fd]) != 0)
		*line = ft_strdupdel(&fd_arr[fd]);
	return (1);
}
