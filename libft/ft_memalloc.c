/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:38:06 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/28 15:08:03 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(ret = (char*)malloc(size)))
		return (NULL);
	while (i < size)
		ret[i++] = '\0';
	return (ret);
}
