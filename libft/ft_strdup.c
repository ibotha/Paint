/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:16:59 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/19 10:13:03 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		length;
	char	*ret;

	length = (int)ft_strlen(str);
	if (!(ret = (char*)malloc(sizeof(char) * (length + 1))))
		ret = NULL;
	else
	{
		while (length >= 0)
		{
			ret[length] = str[length];
			length--;
		}
	}
	return (ret);
}
