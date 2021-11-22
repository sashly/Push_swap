/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:20:45 by sashly            #+#    #+#             */
/*   Updated: 2021/04/14 12:21:16 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_mod(char *str, int offset_old, int *offset_new)
{
	char	*s;

	s = str;
	while (*str && *str != '\n')
		str++;
	*offset_new = 0;
	if (*str)
		*offset_new = offset_old + (str - s) + 1;
	return (str - s);
}

static char	*ft_append_mod_ret(char *to_free, char *ret)
{
	if (to_free)
		free(to_free);
	return (ret);
}

static char	*ft_append_mod(char *str, const char *buf, int newlen)
{
	char	*ret;
	char	*s;
	char	*r;
	int		slen;

	slen = 0;
	if (str)
		slen = ft_strlen(str);
	s = str;
	ret = (char *)malloc(sizeof(char) * (slen + newlen + 1));
	if (!ret)
		return (ft_append_mod_ret(str, NULL));
	r = ret;
	if (str)
		while (*str)
			*(ret++) = *(str++);
	while (newlen--)
		*(ret++) = *(buf++);
	*ret = '\0';
	return (ft_append_mod_ret(s, r));
}

static int	get_next_line_init(char **line, int *offset, int *offset_new,
							  int *ret)
{
	if (!line || BUFFER_SIZE <= 0)
		return (0);
	*line = NULL;
	*offset = *offset_new;
	*offset_new = 0;
	*ret = 1;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	offset_new;
	int			offset;
	int			newlen;
	int			ret;

	if (!get_next_line_init(line, &offset, &offset_new, &ret))
		return (-1);
	while (1)
	{
		if (!offset)
			ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		newlen = ft_strlen_mod(buf + offset, offset, &offset_new);
		*line = ft_append_mod(*line, buf + offset, newlen);
		if (!(*line))
			return (-1);
		if (offset_new)
			break ;
		offset = offset_new;
		if (ft_memset(buf, 0, sizeof(char) * BUFFER_SIZE) && !ret)
			break ;
	}
	return (!(!ret));
}
