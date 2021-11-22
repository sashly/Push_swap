/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:43:03 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:43:06 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

static int	ft_split_charset_strlen_mod(char *str, char *charset)
{
	char	*s;

	s = str;
	while (*str && !ft_is_in_str(charset, *str))
		str++;
	return (str - s);
}

static int	ft_split_charset_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str && !ft_is_in_str(charset, *str) && ++count)
			while (*str && !ft_is_in_str(charset, *str))
				str++;
		while (*str && ft_is_in_str(charset, *str))
			str++;
	}
	return (count);
}

static char	*ft_split_charset_strdup_mod(const char *s, int len)
{
	char	*dup;
	char	*d;

	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	d = dup;
	while (*s && len--)
		*(dup++) = *(s++);
	*dup = '\0';
	return (d);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**split;
	int		size;
	int		i;
	int		slen;

	size = ft_split_charset_count_words(str, charset);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*str && ft_is_in_str(charset, *str))
			str++;
		slen = ft_split_charset_strlen_mod(str, charset);
		split[i] = ft_split_charset_strdup_mod(str, slen);
		if (!split[i++])
			return (NULL);
		str += slen;
	}
	split[i] = NULL;
	return (split);
}
