/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenoist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:57:25 by tbenoist          #+#    #+#             */
/*   Updated: 2016/01/08 14:02:25 by tbenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int fd;
	int fd2;
	char *line;

	line = NULL;
	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	get_next_line(fd, &line);
	printf("output= %s\n", line);
	get_next_line(fd2, &line);
	printf("output= %s\n", line);
	get_next_line(fd2, &line);
	printf("output= %s\n", line);
	return (0);
}
