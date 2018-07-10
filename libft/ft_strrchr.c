/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:52:52 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/30 08:09:22 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	while (i >= 0 && str[i] != c)
		--i;
	if (str[i] == c)
		return ((char*)&str[i]);
	return (NULL);
}
