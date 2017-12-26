/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:14:02 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/20 13:14:05 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_result(int fd, char **res, char **line)
{
	char	*tmp;
	int		lenght;
	int		i;

	i = 0;
	if ((tmp = ft_strchr(*res, '\n')) != 0)
	{
		lenght = tmp - *res;
		*line = ft_memalloc(lenght);
		ft_memcpy(*line, res, lenght);
		tmp++;
		free(res);
		*res = tmp;
		return (1);
	}
	return (0);
}

int		read_from_file(int fd, char **res, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		read_bytes;

	read_bytes = 0;
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (read_bytes == -1)
			return (-1);
		buff[read_bytes] = '\0';
		if (!(*res))
			*res = ft_strdup(buff);
		else
			ft_strjoin(*res, buff);
		if (check_result(fd, res, line))
			return (1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*res = NULL;

	if (!res)
		read_from_file(fd, &res, line);
	else if (check_result(fd, &res, line) == 1)
		return (1);
	else if (read_from_file(fd, &res, line) == -1)
		return (-1);
	while (read_from_file(fd, &res, line) != 1)
		;
	return (0);
}
