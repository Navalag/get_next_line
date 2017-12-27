/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:09:31 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/27 14:09:34 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_result(char **res, char **line)
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

int		read_from_fd(int fd, char **res, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		read_bytes;
	// char	*sys_tmp;

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

int		get_next_line(const int fd, char **line)
{
	static	char	*res = NULL;
			int		ret_val;

	if (res == NULL)
		ret_val = read_from_fd(fd, &res, line);
	else if (check_result(&res, line) == 1)
		return (1);
	else
		ret_val = read_from_fd(fd, &res, line);
	if (ret_val == 0 && res != NULL && *res != '\0')
	{
		*line = ft_strdup(res);
		free(res);
		res = NULL;
		return (1);
	}
	return (ret_val);
}
