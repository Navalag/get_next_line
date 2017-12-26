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

static void		to_end(char *buff, int i, char **line)
{
	buff[i] = '\0';
	*line = ft_memalloc(i);
	ft_memcpy(*line, buff, i);
	free(buff);
}

int		get_next_line(const int fd, char **line)
{
	static	char	buff[BUFF_SIZE + 1] = {'\0'};
			char	*p_buff;
			char	*res;
			char	*tmp;
			int		read_res;
			int		i;
			int		j;
			int		k;

	res = ft_memalloc(BUFF_SIZE);
	read_res = 0;
	j = 0;
	k = 1;
	i = 0;
	p_buff = buff;
	while ((read_res = read(fd, buff, BUFF_SIZE)))
	{
		if (read_res == -1)
			return (-1);
		buff[read_res] = '\0';
		i = 0;
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			res[i + j] = buff[i];
			i++;
		}
		printf("i = %i\n", i);
		printf("buff = %s\n", buff);
		printf("res = %s\n", res);
		if (buff[i] == '\n' || (buff[i] == '\0' && i != BUFF_SIZE))
		{
			printf("check\n");
			to_end(res, i + j, line);
			p_buff = ft_strcpy(buff, &buff[i]);
			printf("strcpy = %s\n", buff);
			return (1);
		}
		if (i + j == BUFF_SIZE * k)
		{
			k *= 2;
			tmp = ft_memalloc(BUFF_SIZE * k);
			ft_memcpy(tmp, res, i + j);
			free(res);
			res = tmp;
			j += BUFF_SIZE;
		}
	}
	return (0);
}
