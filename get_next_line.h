/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:32:13 by adhaka            #+#    #+#             */
/*   Updated: 2023/04/30 04:46:09 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr_gtnl(const char *s, int c);
char	*ft_strjoin_gtnl(char *s1, char *s2);
size_t	ft_strlcpy_gtnl(char *dst, char *src, size_t size);
char	*ft_newbuf_gtnl(char *buf);
char	*ft_gline_gtnl(char *buf);
char	*ft_catchbuf_gtnl(int fd, char *initialbuf);
char	*get_next_line(int fd);

#endif
