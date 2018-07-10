/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:53:34 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/30 08:14:19 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int front;
	int back;

	if (!s)
		return (NULL);
	front = 0;
	back = ft_strlen(s) - 1;
	while (s[front] == ' ' || s[front] == '\t' || s[front] == '\n')
	{
		++front;
	}
	if (s[front] == '\0')
		return (ft_strdup(""));
	while (s[back] == ' ' || s[back] == '\t' || s[back] == '\n')
		--back;
	return (ft_strsub(s, front, back - front + 1));
}
