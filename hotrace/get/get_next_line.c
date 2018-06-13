/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:42:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/25 12:30:39 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_list_fd(char **buff)
{
	if (!(*buff))
	{
		*buff = ft_memalloc(1);
		ft_bzero(*buff, 1);
	}
	return (*buff);
}

static int	ft_read(char **buff, int fd)
{
	char	temp[BUFF_SIZE + 1];
	int		result;
	char	*free_me;

	result = 0;
	while (!(ft_strchr(*buff, '\n'))
		&& (result = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[result] = '\0';
		free_me = *buff;
		*buff = ft_strjoin(*buff, temp);
		ft_memdel((void**)&free_me);
	}
	return (result == -1) ? 0 : 1;
}

int			get_next_line(const int fd, char **line)
{
	static char		*buff = NULL;
	char			*ptr;

	if (fd < 0 || fd > LIMIT_FD || line == NULL || BUFF_SIZE < 1)
		return (-1);
	buff = ft_list_fd(&buff);
	if (!(ft_read(&buff, fd)))
		return (-1);
	if (!(buff[0]))
		return (0);
	ptr = ft_strchr(buff, '\n');
	if (!ptr && buff)
	{
		*line = ft_strdup(buff);
		buff[0] = '\0';
		return (1);
	}
	else
		*line = ft_strsub(buff, 0, ptr - buff);
	buff = ft_memmove(buff, ptr + 1, ft_strlen(ptr));
	return (1);
}
