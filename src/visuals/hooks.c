/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:36:45 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/10 17:44:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuals.h"

int	key_add(int keycode, char *keys)
{
	keys[keycode] = 1;
	return (keycode);
}

int	key_remove(int keycode, char *keys)
{
	keys[keycode] = 0;
	return (keycode);
}

void	preview(int col, t_env *env, t_xy pos, t_xy size)
{
	t_mlx			mlx;
	t_xy			pixel;

	mlx.mlx = env->mlx.mlx;
	mlx.win = env->mlx.win;
	mlx.height = size[1];
	mlx.width = size[0];
	if (!(mlx.img = mlx_new_image(env->mlx.mlx, size[0], size[1])))
		die("\x1b[31mImage Creation Fail\x1b[0m");
	if (!(mlx.img_buff = (unsigned char*)mlx_get_data_addr(mlx.img, &mlx.bpp,
		&mlx.ll, &mlx.end)))
		die("\x1b[31mImage Buff Collection Fail\x1b[0m");
	mlx.bpp /= 8;
	pixel[1] = -1;
	while (++(pixel[1]) < size[1])
	{
		pixel[0] = -1;
		while (++(pixel[0]) < size[0])
			put_pixel(&mlx, col, pixel[0], pixel[1]);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, pos[0], pos[1]);
	mlx_destroy_image(mlx.mlx, mlx.img);
}

int	key_hk(t_env *env)
{
	char *where;
	char *temp;
	char *temp2;
	static unsigned int draw_col = 0xffffffff;
	static t_xy x = {0,0};
	static t_xy y = {5,5};

	if (env->keys[esc])
		close_hk(env);
	if (env->keys[up])
		x[1] -= 1 + env->keys[shift] * 4;
	if (env->keys[down])
		x[1] += 1 + env->keys[shift] * 4;
	if (env->keys[left])
		x[0] -= 1 + env->keys[shift] * 4;
	if (env->keys[right])
		x[0] += 1 + env->keys[shift] * 4;
	x[0] = env->mouse.pos[0] - (y[0] / 2);
	x[1] = env->mouse.pos[1] - (y[1] / 2);
	if (env->keys[ctrl] && env->mouse.left)
	{
		draw_col = ALP_I(draw_col) * 0x01000000;
		draw_col += env->mlx.img_buff[env->mouse.pos[0] * env->mlx.bpp + env->mouse.pos[1] * env->mlx.ll];
		draw_col += env->mlx.img_buff[env->mouse.pos[0] * env->mlx.bpp + env->mouse.pos[1] * env->mlx.ll + 1] * 0x000100;
		draw_col += env->mlx.img_buff[env->mouse.pos[0] * env->mlx.bpp + env->mouse.pos[1] * env->mlx.ll + 2] * 0x00010000;
	}
	if (env->keys[key_red])
	{
		if (RED(draw_col) != (env->keys[shift] ? 0x00 : 0xff))
			draw_col = env->keys[shift] ? (draw_col - 0x00010000) : (draw_col + 0x00010000);
	}
	if (env->keys[key_green])
	{
		if (GRN(draw_col) != (env->keys[shift] ? 0x00 : 0xff))
			draw_col = env->keys[shift] ? (draw_col - 0x00000100) : (draw_col + 0x00000100);
	}
	if (env->keys[key_blue])
	{
		if (BLU(draw_col) != (env->keys[shift] ? 0x00 : 0xff))
			draw_col = env->keys[shift] ? (draw_col - 0x00000001) : (draw_col + 0x00000001);
	}
	if (env->keys[key_alpha])
	{
		if (ALP_I(draw_col) != (env->keys[shift] ? 0x00 : 0xff))
			draw_col = env->keys[shift] ? (draw_col - 0x01000000) : (draw_col + 0x01000000);
	}
	if (env->keys[plus])
	{
		y[0]++;
		y[1]++;
	}
	if (env->keys[minus])
	{
		if (y[0] > 1)
			y[0]--;
		if (y[1] > 1)
			y[1]--;
	}
	if (env->keys[home])
		make_image(&env->mlx, env->scene.obj);
	if (env->mouse.left && !env->keys[ctrl])
		draw_box(x, y, draw_col, &env->mlx);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	preview(0xff000000 + RED(draw_col) * 0x00010000 + GRN(draw_col) * 0x00000100 + BLU(draw_col), env, x, y);
	temp = ft_itoa(x[0]);
	where = ft_strjoin(temp, ", ");
	free(temp);
	temp = ft_itoa(x[1]);
	temp2 = ft_strjoin(where, temp);
	free(temp);
	temp = ft_strjoin(temp2, " RGBA: ");
	free(temp2);
	where = ft_itoa(RED(draw_col));
	temp2 = ft_strjoin(temp, where);
	free(where);
	free(temp);
	temp = ft_strjoin(temp2, ", ");
	free(temp2);
	where = ft_itoa(GRN(draw_col));
	temp2 = ft_strjoin(temp, where);
	free(where);
	free(temp);
	temp = ft_strjoin(temp2, ", ");
	free(temp2);
	where = ft_itoa(BLU(draw_col));
	temp2 = ft_strjoin(temp, where);
	free(temp);
	free(where);
	temp = ft_strjoin(temp2, ", ");
	free(temp2);
	where = ft_itoa(ALP_I(draw_col));
	temp2 = ft_strjoin(temp, where);
	free(temp);
	free(where);
	mlx_string_put(env->mlx.mlx, env->mlx.win, 0, 0, 0xff000000, temp2);
	free(temp2);
	return (0);
}

int	close_hk(t_env *env)
{
	if (env->mlx.win)
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
	if (env->mlx.img)
		mlx_destroy_image(env->mlx.mlx, env->mlx.img);
	if (env->scene.obj)
		free(env->scene.obj);
	if (env->scene.light)
		free(env->scene.light);
	die("\x1b[32mClosed!\x1b[0m");
	return (0);
}
