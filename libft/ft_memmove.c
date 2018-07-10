/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:28:18 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/22 17:48:53 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *str1, const void *str2, size_t n)
{
	if (str1 == str2)
		return (str1);
	if (str1 > str2)
		ft_memrcpy(str1, str2, n);
	else
		ft_memcpy(str1, str2, n);
	return (str1);
}
