/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:34:57 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/04 16:21:08 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <stdio.h>
#include <math.h>
#include "libft.h"

#define FILLVEC(V, X, Y, Z) (V[0] = X, V[1] = Y, V[2] = Z)

typedef float	t_vec[4];

void	put_vector(t_vec vec, const char *name);
float	dot(t_vec a, t_vec b);
float	*v_cross(t_vec a, t_vec b, t_vec ret);
float	length(t_vec v);
void	normalize(t_vec v);
void	vec_from_str(t_vec ret, char *str);
float	*v_multi(t_vec a, float b, t_vec ret);
float	*v_sub(t_vec a, t_vec b, t_vec ret);
float	*v_add(t_vec a, t_vec b, t_vec ret);
float	*v_mult(t_vec a, t_vec b, t_vec ret);
float	*v_div(t_vec a, t_vec b, t_vec ret);

#endif
