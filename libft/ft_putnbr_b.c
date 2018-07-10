/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:17:35 by ibotha            #+#    #+#             */
/*   Updated: 2018/06/13 09:20:59 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_b(int n, char *base)
{
	int b;

	b = (int)ft_strlen(base);
	if (n == -2147483648)
		ft_putstr("-00-");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= b)
			ft_putnbr(n / b);
		ft_putchar(base[n % b]);
	}
}
