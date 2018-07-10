/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:41:24 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/05 15:02:49 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	add_light(int fd, char **line, t_scene *s)
{
	int		exit;
	t_light	*light;

	if (!(light = (t_light*)ft_memalloc(sizeof(t_light) * ++(s->n_light))))
		die("\x1b[31mMALLOC FAIL\x1b[0m");
	ft_memmove(light, s->light, sizeof(t_light) * (s->n_light - 1));
	if (s->light)
		free(s->light);
	free(*line);
	exit = get_next_line(fd, line);
	light[s->n_light - 1].col = 0x00ffffff;
	while ((*line)[0] == '\t')
	{
		if (ft_strnequ("\torigin", *line, 7))
			vec_from_str(light[s->n_light - 1].org, &(*line)[7]);
		else if (ft_strnequ("\tintensity", *line, 10))
			light[s->n_light - 1].intensity = ft_atod(&(*line)[10]);
		else if (ft_strnequ("\tcolour", *line, 7))
			light[s->n_light - 1].col = ft_atoi_b(&(*line)[7], HEX);
		free(*line);
		exit = get_next_line(fd, line);
	}
	s->light = light;
	return (exit);
}

void	parse(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		exit;

	exit = 1;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	while (exit)
	{
		if (exit < 0)
			die("\x1b[31mGNL_Error\x1b[0m");
		if (ft_strnequ("light", line, 5))
			exit = add_light(fd, &line, scene);
		else if (ft_strnequ("sphere", line, 6))
			exit = add_obj(fd, &line, scene, NULL);
		else
		{
			free(line);
			exit = get_next_line(fd, &line);
		}
	}
	free(line);
	close(fd);
}
