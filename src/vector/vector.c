/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:51:33 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/04 14:34:34 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	dot(t_vec a, t_vec b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

float	*v_cross(t_vec a, t_vec b, t_vec ret)
{
	t_vec temp;

	temp[0] = a[1] * b[2] - a[2] * b[1];
	temp[1] = a[2] * b[0] - a[0] * b[2];
	temp[2] = a[0] * b[1] - a[1] * b[0];
	ret[0] = temp[0];
	ret[1] = temp[1];
	ret[2] = temp[2];
	return (ret);
}

float	length(t_vec v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

void	normalize(t_vec v)
{
	float l;

	l = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	if (l > 0)
	{
		l = 1 / sqrt(l);
		v[0] *= l;
		v[1] *= l;
		v[2] *= l;
	}
}
/*
float	*v_rot_v(float a, t_vec axis, t_vec r)
{
	float	c;
	float	s;
	float	cb;
	float	m[4][4];

	c = cos(a);
	s = sin(a);
	cb = 1.0 - c;
	m[0][0] = axis[0] * axis[0] * cb + c;
	m[1][0] = axis[1] * axis[0] * cb + axis[2] * s;
	m[2][0] = axis[2] * axis[0] * cb - axis[1] * s;
	m[0][1] = axis[1] * axis[0] * cb - axis[2] * s;
	m[1][1] = axis[1] * axis[1] * cb + c;
	m[2][1] = axis[2] * axis[1] * cb + axis[0] * s;
	m[0][2] = axis[0] * axis[2] * cb + axis[1] * s;
	m[1][2] = axis[2] * axis[1] * cb - axis[0] * s;
	m[2][2] = axis[2] * axis[2] * cb + c;
	transformvec(m, r, r);
	return (r);
}
*/
void	put_vector(t_vec vec, const char *name)
{
	printf("%s: (x: %lf, y: %lf, z: %lf)\n", name, vec[0], vec[1], vec[2]);
}
