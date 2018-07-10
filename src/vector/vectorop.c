/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:53:50 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/04 16:21:18 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	*v_mult(t_vec a, t_vec b, t_vec ret)
{
	ret[0] = a[0] * b[0];
	ret[1] = a[1] * b[1];
	ret[2] = a[2] * b[2];
	return (ret);
}

float	*v_div(t_vec a, t_vec b, t_vec ret)
{
	if (b[0])
		ret[0] = a[0] / b[0];
	if (b[1])
		ret[1] = a[1] / b[1];
	if (b[2])
		ret[2] = a[2] / b[2];
	return (ret);
}

float	*v_add(t_vec a, t_vec b, t_vec ret)
{
	ret[0] = a[0] + b[0];
	ret[1] = a[1] + b[1];
	ret[2] = a[2] + b[2];
	return (ret);
}

float	*v_sub(t_vec a, t_vec b, t_vec ret)
{
	ret[0] = a[0] - b[0];
	ret[1] = a[1] - b[1];
	ret[2] = a[2] - b[2];
	return (ret);
}

float	*v_multi(t_vec a, float b, t_vec ret)
{
	ret[0] = a[0] * b;
	ret[1] = a[1] * b;
	ret[2] = a[2] * b;
	return (ret);
}
