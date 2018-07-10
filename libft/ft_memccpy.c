/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:31:53 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/31 13:14:12 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t				i;
	unsigned char		*temp;
	const unsigned char	*temp2;

	i = 0;
	temp = (unsigned char*)str1;
	temp2 = (const unsigned char*)str2;
	while (i < n)
	{
		temp[i] = temp2[i];
		if (temp2[i] == (unsigned char)c)
			return ((void*)&temp[i + 1]);
		i++;
	}
	return (NULL);
}
