/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:32:05 by adhaka            #+#    #+#             */
/*   Updated: 2023/04/30 04:55:06 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	if (!str)
		return (0);
	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr_gtnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)&*s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_gtnl(char *s1, char *s2)
{
	char	*new;
	size_t	a;
	size_t	b;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (free(s1), NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a] != '\0')
	{
		new[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
		new[a++] = s2[b++];
	new[a] = '\0';
	return (free(s1), new);
}

size_t	ft_strlcpy_gtnl(char *dst, char *src, size_t size)
{
	size_t		a;

	a = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while ((a < (size - 1)) && (src[a] != '\0'))
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (ft_strlen(src));
}
