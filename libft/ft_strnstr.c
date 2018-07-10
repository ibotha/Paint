/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:45:30 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/24 14:54:08 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t hay_search;
	size_t needle_search;
	size_t ret_index;

	hay_search = 0;
	needle_search = 0;
	ret_index = 0;
	while (haystack[hay_search] && needle[needle_search] && hay_search < n)
		if (haystack[hay_search++] != needle[needle_search++])
		{
			hay_search = ++ret_index;
			needle_search = 0;
		}
	if (!needle[needle_search])
		return ((char*)haystack + ret_index);
	return (NULL);
}
