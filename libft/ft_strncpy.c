/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/31 13:25:53 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *ret, const char *str, size_t n)
{
	size_t	length;
	int		i;

	length = 0;
	i = 0;
	while (length < n)
	{
		if (str[i])
		{
			ret[length] = str[i];
			i++;
		}
		else
			ret[length] = '\0';
		length++;
	}
	return (ret);
}
