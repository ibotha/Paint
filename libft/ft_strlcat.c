/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:34:12 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/24 14:36:18 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t og_dstlen;
	size_t sindex;

	sindex = -1;
	og_dstlen = ft_strlen(dest);
	if (og_dstlen >= n)
		return (n + ft_strlen(src));
	while (src[++sindex] && (og_dstlen + sindex + 1) < n)
		dest[og_dstlen + sindex] = src[sindex];
	dest[og_dstlen + sindex] = '\0';
	return (og_dstlen + ft_strlen(src));
}
