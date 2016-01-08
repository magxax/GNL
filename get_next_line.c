/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenoist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:09:23 by tbenoist          #+#    #+#             */
/*   Updated: 2016/01/08 14:39:41 by tbenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

t_pos	*create_pos(int fd)
{
	t_pos	*new;

	if((new = (t_pos*)malloc(sizeof(t_pos))))
	{
		new->fd = fd;
		new->next = NULL;
	}
	return (new);
}

int		line_in_list(int const fd, char **line, char *buf, t_pos *tmp)
{
	if (tmp->fd == fd)
	{
		if (!ft_strchr(tmp->last_line, '\n'))
		{
			*line = ft_strdup(tmp->last_line);
			if (!(*line))
				return (-1);
		}
		else
		{
			ft_strcpy(buf, tmp->last_line);
			tmp->last_line = ft_strchr(tmp->last_line, '\n') + 1;
			*ft_strchr(buf, '\n') = '\0';
			*line = ft_strjoin(*line, buf);
			return (1);
		}
	}
	else
	tmp->next = create_pos(fd);
	return(0);
}

int get_next_line(int const fd, char **line)
{
	char			*buf;
	int				ret;
	static t_pos	*list = NULL;
	t_pos			*tmp;

	tmp = list;
	buf = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (!(*line) || !(buf))
		return (-1);
	printf("fdrec = %d\n", fd);
	if (list)
	{
		while (tmp->next && tmp->fd != fd)
		{
			tmp = tmp->next;
			printf("fd= %d\ncontent = %s\n", tmp->fd, tmp->last_line);
		}
		ret = line_in_list(fd, line, buf, tmp);
		if (ret)
			return (ret);
	}
	else
	{
		list = create_pos(fd);
		tmp = list;
	}
	while(((ret = read(fd, buf, BUFF_SIZE)) > 0 && !(ft_strchr(buf, '\n'))))
	{
		*line = ft_strjoin(*line, buf);
		if (!(*line))
			return (-1);
	}
	if (ret < 0)
		return (-1);
	if (ft_strchr(buf, '\n'))
	{
		tmp->last_line = ft_strdup(ft_strchr(buf, '\n') + 1);
		*ft_strchr(buf, '\n') = '\0';
	}
	else
		tmp->last_line = "";
	*line = ft_strjoin(*line, buf);
	return ret ? 1 : 0;
}
