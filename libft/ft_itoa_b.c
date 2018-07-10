/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:25:34 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/28 09:03:21 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(int n, int base)
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
		n /= base;
	}
	return (size);
}

char		*ft_itoa_b(int n, char *base)
{
	int		size;
	char	*ret;

	if (n == 0 || n == -2147483648)
		if (!(ret = ft_strnew(1)))
			return (NULL);
		else
			ret[0] = '0';
	else
	{
		size = getsize(n, ft_strlen(base));
		if (!(ret = ft_strnew(size)))
			return (NULL);
		if (n < 0)
		{
			ret[0] = '-';
			n *= -1;
		}
		while (--size >= 0)
		{
			ret[size] = base[n % ft_strlen(base)];
			n /= ft_strlen(base);
		}
	}
	return (ret);
}
