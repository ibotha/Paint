/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:17:23 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/10 11:47:01 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visuals.h"

static void	draw_liney(t_xy a, t_xy b, t_mlx *mlx)
{
	double	change;
	double	grad;
	double	i;

	change = b[1] - a[1];
	grad = (b[0] - a[0]) / change;
	i = -1;
	while (++i < (ABS(change)))
		put_pixel(mlx, mlx->col, a[0] + (DR(i)) * grad, a[1] + (DR(i)));
}

void		draw_line(t_xy a, t_xy b, t_mlx *mlx)
{
	double	change;
	double	ychange;
	double	grad;
	double	i;

	change = b[0] - a[0];
	ychange = b[1] - a[1];
	if (ABS(ychange) > (ABS(change)))
		draw_liney(a, b, mlx);
	else
	{
		grad = ychange / change;
		i = -1;
		while (++i < ABS(change))
			put_pixel(mlx, mlx->col, a[0] + DR(i), a[1] + DR(i) * grad);
	}
}

void		put_pixel(t_mlx *mlx, int c, int x, int y)
{
	int i;

	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
	i = x * mlx->bpp + y * mlx->ll;
	mlx->img_buff[i] *= (1 - ALP(c));
	mlx->img_buff[i] += BLU(c) * ALP(c);
	mlx->img_buff[i + 1] *= (1 - ALP(c));
	mlx->img_buff[i + 1] += GRN(c) * ALP(c);
	mlx->img_buff[i + 2] *= (1 - ALP(c));
	mlx->img_buff[i + 2] += RED(c) * ALP(c);
}

void		draw_box(t_xy start, t_xy dim, t_mlx *mlx)
{
	int y;
	int x;

	if (dim[1] < 0 || dim[0] < 0 || dim[1] > WIN_H || dim[0] > WIN_W)
		return ;
	y = -1;
	while (++y < dim[0])
	{
		x = -1;
		while (++x < dim[0])
			put_pixel(mlx, mlx->col, start[0] + x, start[0] + y);
	}
}
