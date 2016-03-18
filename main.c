/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenoist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:36:32 by tbenoist          #+#    #+#             */
/*   Updated: 2016/03/18 16:16:19 by tbenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int fd;
	char *line;
	int res = 1;

	fd = open ("test", O_RDONLY);
	line = (char*)malloc(1);
	while (res)
		printf("res= %d\n%s\n", res = get_next_line(fd, &line), line);
	return (0);
}
