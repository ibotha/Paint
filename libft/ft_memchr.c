/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:57:22 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/19 12:15:05 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *t;

	t = s;
	while (n > 0)
	{
		if (*t == (unsigned char)c)
			return ((void*)t);
		++t;
		n--;
	}
	return (NULL);
}
