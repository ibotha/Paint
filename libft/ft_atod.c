/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:19:45 by ibotha            #+#    #+#             */
/*   Updated: 2018/06/22 18:25:44 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoiprereq(const char **s)
{
	int sign;

	sign = 1;
	while (**s == ' ' || **s == '\t' || **s == '\f' || **s == '\v'
			|| **s == '\n' || **s == '\r')
		++*s;
	if (**s == '-')
	{
		sign = -1;
		++*s;
	}
	else if (**s == '+')
		++*s;
	return (sign);
}

double			ft_atod(const char *str)
{
	double		ret;
	double		pret;
	double		divisor;
	int			sign;
	int			i;

	ret = 0;
	pret = 0;
	divisor = 1;
	sign = atoiprereq(&str);
	i = -1;
	while (ft_isdigit(str[++i]))
	{
		ret *= 10;
		ret += str[i] - '0';
		if (ret < 0)
			return (0 - (sign == 1));
	}
	i += (str[i] == '.');
	while (ft_isdigit(str[i]))
	{
		divisor *= 0.1;
		pret += (double)(str[i] - '0') * divisor;
		i++;
	}
	return ((ret + pret) * (double)sign);
}
