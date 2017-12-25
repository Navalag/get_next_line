/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:13:44 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/20 13:13:46 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	if (argc != 2)
	{
		printf("usage: ./get_next_line source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	i = 0;
	while (i < 5)
	{
		get_next_line(fd, &str);
		// printf("fd - %i\n", fd);
		printf("%s\n", str);
		i++;
	}
	// system("leaks get_next_line");
	return (0);
}
