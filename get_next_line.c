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

static void		to_end(char *buf, int i, char **line)
{
	buf[i - 1] = 0;
	*line = ft_memalloc(i);
	ft_memcpy(*line, buf, i);
	free(buf);
}

// void	check_buff_size(char **buf, int i)
// {
// 	char	*tmp;
// 	static int		k;

// 	k = 1;
// 	if (i == BUF_SIZE * k)
// 	{
// 		k *= 2;
// 		tmp = ft_memalloc(BUF_SIZE * k);
// 		ft_memcpy(tmp, buf, i);
// 		free(buf);
// 		buf = &tmp;
// 	}
// }

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		ret;
	int		k;
	char	*buf;
	char	*tmp;

	i = 0;
	k = 1;
	buf = ft_memalloc(BUFF_SIZE);
	ret = 0;
	while (buf[i - 1] != '\n' && ret == 0)
	{
		// check_buff_size(*buf, i);
		if (i == BUFF_SIZE * k)
		{
			k *= 2;
			tmp = ft_memalloc(BUFF_SIZE * k);
			ft_memcpy(tmp, buf, i);
			free(buf);
			buf = tmp;
		}
		ret = read(fd, &buf[i++], 1);
		// printf("%i\n", ret);
	}
	printf("%i\n", ret);
	to_end(buf, i, line);
	return (ret);
}
