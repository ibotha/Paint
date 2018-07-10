/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:42:08 by ibotha            #+#    #+#             */
/*   Updated: 2018/06/09 11:34:25 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*fail(t_list **list)
{
	free(*list);
	return (NULL);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ret->content_size = content_size;
	ret->content = NULL;
	ret->next = NULL;
	if (content)
	{
		if (!(ret->content = ft_memalloc(content_size)))
			return (fail(&ret));
		ft_memcpy(ret->content, content, ret->content_size);
	}
	else
		ret->content_size = 0;
	return (ret);
}
