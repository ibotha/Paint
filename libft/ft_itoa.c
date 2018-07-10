/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:55:08 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/23 08:32:37 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		++size;
	}
	while (n != 0)
	{
		++size;
		n /= 10;
	}
	return (size);
}

static char	*mincase(int n)
{
	char *ret;

	if (n == -2147483648)
		if (!(ret = ft_strdup("-2147483648")))
			return (NULL);
	if (n == 0)
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		else
			ret[0] = '0';
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*ret;

	if (n == -2147483648 || n == 0)
		return (mincase(n));
	else
	{
		size = getsize(n);
		if (!(ret = ft_strnew(size)))
			return (NULL);
		if (n < 0)
		{
			ret[0] = '-';
			n *= -1;
		}
		while (--size >= (ret[0] == '-'))
		{
			ret[size] = n % 10 + '0';
			n /= 10;
		}
	}
	return (ret);
}
