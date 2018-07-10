/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:45:53 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/10 17:31:27 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuals.h"
#include "die.h"

void	 initiate(t_mlx *mlx, char *title)
{
	if (!mlx->mlx)
		if (!(mlx->mlx = mlx_init()))
			die("\x1b[31mMLX Init Fail\x1b[0m");
	if (!mlx->win)
		if (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, title)))
			die("\x1b[31mWindow Creation Fail\x1b[0m");
	if (!mlx->img)
	{
		if (!(mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)))
			die("\x1b[31mImage Creation Fail\x1b[0m");
		if (!(mlx->img_buff = (unsigned char*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->ll, &mlx->end)))
			die("\x1b[31mImage Buff Collection Fail\x1b[0m");
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx->height = WIN_H;
	mlx->width = WIN_W;
	mlx->bpp /= 8;
}
