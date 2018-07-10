/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:20:35 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/22 11:16:21 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	atoiprereq(const char **s)
{
	int isneg;

	isneg = 0;
	while (**s == ' ' || **s == '\t' || **s == '\f' || **s == '\v'
			|| **s == '\n' || **s == '\r')
		++*s;
	if (**s == '-')
	{
		isneg = 1;
		++*s;
	}
	else if (**s == '+')
		++*s;
	return (isneg);
}

int			ft_atoi(const char *str)
{
	long long	ret;
	int			isneg;
	const char	*s;

	s = str;
	ret = 0;
	isneg = atoiprereq(&s);
	while (ft_isdigit(*s))
	{
		ret *= 10;
		ret += *s - '0';
		if (ret < 0 && isneg == 1)
			return (0);
		if (ret < 0)
			return (-1);
		++s;
	}
	if (isneg)
		ret *= -1;
	return (ret);
}
