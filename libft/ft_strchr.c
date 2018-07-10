/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:41:43 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/17 12:17:23 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		++i;
	if (str[i] == c)
		return ((char*)&str[i]);
	return (NULL);
}
