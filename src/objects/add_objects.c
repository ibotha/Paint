/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:36:38 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/05 15:02:20 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	fill_obj(t_obj *obj, char *line)
{
	if (ft_strnequ("\torigin", line, 7))
		vec_from_str(obj->org, &(line)[7]);
	else if (ft_strnequ("\tradius", line, 7))
		obj->r = ft_atod(&(line)[7]);
	else if (ft_strnequ("\theight", line, 7))
		obj->height = ft_atod(&(line)[7]);
	else if (ft_strnequ("\twidth", line, 6))
		obj->width = ft_atod(&(line)[6]);
	else if (ft_strnequ("\ty_axis", line, 7))
		vec_from_str(obj->y_vec, &(line)[7]);
	else if (ft_strnequ("\tcolour", line, 7))
		obj->col = ft_atoi_b(&(line)[7], "0123456789abcdef");
}

int     add_obj(int fd, char **l, t_scene *s, int (*c)(t_obj*, float*))
{
	int		exit;
	t_obj	*obj;

	if (!(obj = (t_obj*)ft_memalloc(sizeof(t_obj) * ++(s->n_obj))))
		die("\x1b[31mMALLOC FAIL\x1b[0m");
	ft_memmove(obj, s->obj, sizeof(t_obj) * (s->n_obj - 1));
	if (s->obj)
		free(s->obj);
	free(*l);
	exit = get_next_line(fd, l);
	obj[s->n_obj - 1].col = 0xffffffff;
	while ((*l)[0] == '\t')
	{
		fill_obj(&obj[s->n_obj - 1], *l);
		free(*l);
		exit = get_next_line(fd, l);
	}
	(obj[s->n_obj - 1]).r2 = (obj[s->n_obj - 1]).r * (obj[s->n_obj - 1]).r;
	(obj + s->n_obj - 1)->coll = c;
	s->obj = obj;
	return (exit);
}
