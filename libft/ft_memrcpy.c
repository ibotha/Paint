/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:35:23 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/21 11:47:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *str1, const void *str2, size_t n)
{
	int			i;
	char		*temp;
	const char	*temp2;

	i = (int)n - 1;
	temp = (char*)str1;
	temp2 = (const char*)str2;
	while (i >= 0)
	{
		temp[i] = temp2[i];
		--i;
	}
	return (str1);
}
