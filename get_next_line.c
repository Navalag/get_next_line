/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:09:31 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/28 10:37:50 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_result(char **res, char **line)
{
	char	*tmp;
	int		lenght;
	int		i;

	i = 0;
	if ((tmp = ft_strchr(*res, '\n')) != 0)
	{
		lenght = tmp - *res;
		*line = ft_strsub(*res, 0, lenght);
		tmp = *res;
		*res = ft_strsub(tmp, lenght + 1, ft_strlen(tmp) - lenght);
		free(tmp);
		return (1);
	}
	return (0);
}

static int		read_from_fd(int fd, char **res, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
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
		{
			tmp = ft_strjoin(*res, buff);
			free(*res);
			*res = tmp;
		}
		if (check_result(res, line))
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*res[FD_AMOUNT];
	int				ret_val;

	if (fd < 0 || fd >= 1024 || line == NULL)
		return (-1);
	if (!res[fd])
		ret_val = read_from_fd(fd, &res[fd], line);
	else if (check_result(&res[fd], line) == 1)
		return (1);
	else
		ret_val = read_from_fd(fd, &res[fd], line);
	if (ret_val == 0 && res[fd] != NULL && *res[fd] != '\0')
	{
		*line = ft_strdup(res[fd]);
		free(res[fd]);
		res[fd] = NULL;
		return (1);
	}
	return (ret_val);
}
