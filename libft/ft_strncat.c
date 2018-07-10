/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:12:26 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/17 12:25:01 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *ret, const char *str, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (ret[i] != '\0')
		++i;
	while (str[j] != '\0' && j < n)
		ret[i++] = str[j++];
	ret[i] = '\0';
	return (ret);
}
