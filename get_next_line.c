/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:32:09 by adhaka            #+#    #+#             */
/*   Updated: 2023/05/10 00:15:29 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_catchbuf_gtnl(int fd, char *initialbuf)
{
	char	*buffer;
	int		count;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr_gtnl(initialbuf, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (free(buffer), free(initialbuf), NULL);
		buffer[count] = '\0';
		initialbuf = ft_strjoin_gtnl(initialbuf, buffer);
	}
	return (free(buffer), initialbuf);
}

char	*ft_gline_gtnl(char *buf)
{
	char	*line;
	size_t	a;

	a = 0;
	if (!buf[a])
		return (NULL);
	while ((buf[a] != '\n') && buf[a])
		a++;
	if (buf[a])
		line = (char *)malloc(a + 2);
	else
		line = (char *)malloc(a + 1);
	if (!line)
		return (free(buf), NULL);
	if (buf[a])
		ft_strlcpy_gtnl(line, buf, a + 2);
	else
		ft_strlcpy_gtnl(line, buf, a + 1);
	return (line);
}

char	*ft_newbuf_gtnl(char *buf)
{
	size_t		a;
	size_t		b;
	char		*newbuf;

	a = 0;
	b = ft_strlen(buf);
	while (buf[a] && buf[a] != '\n')
		a++;
	if (!buf[a])
		return (free(buf), NULL);
	newbuf = (char *)malloc((b - a));
	if (!newbuf)
		return (free(buf), NULL);
	a++;
	b++;
	ft_strlcpy_gtnl(newbuf, buf + a, b - a);
	return (free(buf), newbuf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*rline;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_catchbuf_gtnl(fd, buffer);
	if (!buffer)
		return (NULL);
	rline = ft_gline_gtnl(buffer);
	buffer = ft_newbuf_gtnl(buffer);
	return (rline);
}
