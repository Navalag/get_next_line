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

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_1 + len_2) + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[++j] != '\0')
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char*)&s[i]);
	return (0);
}

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	res = ft_memset(res, '\0', size + 1);
	return (res);
}
