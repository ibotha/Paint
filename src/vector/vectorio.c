/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:18:19 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/04 16:18:36 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_from_str(t_vec ret, char *str)
{
	while (*str == ' ' || *str == '\t')
		++str;
	ret[0] = ft_atod(str);
	while (ft_isdigit(*str) || *str == '.')
		++str;
	while (*str == ' ' || *str == '\t')
		++str;
	ret[1] = ft_atod(str);
	while (ft_isdigit(*str) || *str == '.')
		++str;
	while (*str == ' ' || *str == '\t')
		++str;
	ret[2] = ft_atod(str);
}
