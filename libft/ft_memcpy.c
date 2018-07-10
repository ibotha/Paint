/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:31:53 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/17 15:17:42 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*temp;
	const char	*temp2;

	i = 0;
	temp = (char*)str1;
	temp2 = (const char*)str2;
	while (i < n)
	{
		temp[i] = temp2[i];
		++i;
	}
	return (str1);
}
