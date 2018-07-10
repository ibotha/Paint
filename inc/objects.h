/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:18:17 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/04 18:18:41 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

#include "vector.h"
#include "die.h"


typedef struct	s_obj
{
	t_vec		org;
	float		r;
	float		r2;
	float		height;
	float		width;
	t_vec		y_vec;
	int			col;
	int			(*coll)(struct s_obj*, float*);
}				t_obj;
typedef struct	s_light
{
	t_vec	org;
	float	intensity;
	int		col;
}				t_light;
typedef struct	s_scene
{
	t_light	*light;
	int		n_light;
	t_obj	*obj;
	int		n_obj;
}				t_scene;

int     add_obj(int fd, char **l, t_scene *s, int (*c)(t_obj*, float*));

#endif
