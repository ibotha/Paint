/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:08:18 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/19 08:06:49 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = ft_strlen(needle);
	while (haystack[i[0]] && needle[i[1]])
		if (haystack[i[0]++] != needle[i[1]++])
		{
			i[0] += 1 - i[1];
			i[1] = 0;
		}
	if (!needle[i[1]])
		return ((char*)&haystack[i[0] - i[2]]);
	return (NULL);
}
