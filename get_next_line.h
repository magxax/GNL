/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenoist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:04:38 by tbenoist          #+#    #+#             */
/*   Updated: 2016/01/08 13:03:02 by tbenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 100000


typedef		struct	s_pos
{
	int				fd;
	char			*last_line;
	struct	s_pos	*next;
}					t_pos;


int get_next_line(int const fd, char ** line);

#endif
