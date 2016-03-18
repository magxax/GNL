/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenoist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:23:36 by tbenoist          #+#    #+#             */
/*   Updated: 2016/03/18 16:17:27 by tbenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *new;

	if (!ptr)
		return (malloc(size));
	new = (size) ? ft_memalloc(sizeof(char)*size) : malloc(0);
	if (!new)
		return (NULL);
	if(ptr)
	{
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	return (new);
}



int		get_line(char* str, char** line, size_t size, char** save)
{
	char	*tmp;

	tmp = *save;
	if (ft_strchr(str, '\n'))
		{
			if (!(*line = ft_realloc(*line, ft_strlen(*line) + size)))
				return (-1);
			*line = ft_strncat(*line , str, ft_strchr(str, '\n') - str);
			if(!(*save = ft_strdup(ft_strchr(str, '\n') + 1)))
				return (-1);
			free (tmp);
			return (1);
		}
		else
		{
			if (!((*line = ft_realloc(*line, ft_strlen(*line) + size))))
				return (-1);
			*line = ft_strncat(*line, str, size);
		}
		return (0);
}

int			get_next_line(int const fd, char **line)
{
	char			*buf;
	int				ret;
	int				res;
	static char*	save = NULL;

	ret = 1;
	*line = ft_strnew(0);
	if (save)
	{
		if((res = get_line(save, line, ft_strlen(save), &save)))
		{
				return (res);
		}
	}
	buf = ft_strnew(BUFF_SIZE);
	while(ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if((res = get_line(buf, line, ret, &save)))
			return (res);
	}
	return (0);
}
