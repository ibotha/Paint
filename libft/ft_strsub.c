/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:55:39 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/21 14:00:48 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (NULL);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ft_strncpy(ret, s + start, len);
	return (ret);
}
