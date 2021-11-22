/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <sashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:19:53 by sashly            #+#    #+#             */
/*   Updated: 2020/11/06 13:02:13 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign = -1;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*(nptr++) - '0');
	return (sign * res);
}

static int	ft_atoi_positive_check_overflow(const char *nptr, int res)
{
	if (res == 214748364 && (*nptr >= '0' && *nptr <= '7'))
	{
		res = res * 10 + (*nptr - '0');
		if (ft_isdigit(*(++nptr)))
			res = -5;
	}
	else
		if (ft_isdigit(*(nptr++)))
			res = -5;
	if (*nptr)
		return (-1);
	return (res);
}

int	ft_atoi_positive_safe(const char *nptr)
{
	int	res;

	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*(nptr++) - '0');
		if (res > 214748363)
			return (ft_atoi_positive_check_overflow(nptr, res));
	}
	if (*nptr)
		return (-1);
	return (res);
}

int	ft_atoi_check_overflow(const char *nptr, int sign, int *out)
{
	if (*out == 214748364 && (*nptr >= '0' && *nptr <= '7'))
		*out = (*out * 10 + (*(nptr++) - '0')) * sign;
	else if (*out == 214748364 && sign == -1 && *nptr == '8')
		*out = *out * (-10) - (*(nptr++) - '0');
	return (!(*nptr));
}

int	ft_atoi_check(const char *nptr, int *out)
{
	int	sign;

	*out = 0;
	sign = 1;
	if (!*nptr)
		return (0);
	if (*nptr == '-')
	{
		sign = -1;
		if (!*(++nptr))
			return (0);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		*out = *out * 10 + (*(nptr++) - '0');
		if (*out > 214748363)
			return (ft_atoi_check_overflow(nptr, sign, out));
	}
	*out *= sign;
	return (!(*nptr));
}
