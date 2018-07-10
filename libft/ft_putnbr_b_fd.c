/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:17:20 by ibotha            #+#    #+#             */
/*   Updated: 2018/06/13 09:17:24 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_b_fd(int n, char *base, int fd)
{
	int b;

	b = ft_strlen(base);
	if (n == -2147483648)
		ft_putstr_fd("-00-", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= b)
			ft_putnbr_fd(n / b, fd);
		ft_putchar_fd(base[n % b], fd);
	}
}
