/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:36:36 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/21 12:36:38 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char *tmp;

	tmp = s;
	while (n != 0)
	{
		*tmp++ = 0;
		n--;
	}
}

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	res = memset(res, 0, size);
	return (res);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_copy;

	b_copy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_copy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dst)
	{
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
	{
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
