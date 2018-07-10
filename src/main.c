/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:30:15 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/10 16:02:47 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	make_image(t_mlx *mlx, t_obj *obj)
{
	t_xy pixel;

	if (!obj)
		die("because");
	pixel[1] = -1;
	while (++(pixel[1]) < WIN_H)
	{
		pixel[0] = -1;
		while (++(pixel[0]) < WIN_W)
			put_pixel(mlx, 0xffffffff, pixel[0], pixel[1]);
	}
}

int		main(int argc, char **argv)
{
	t_env		env;

	bzero(&env, sizeof(t_env));
	if (argc != 2)
		die("Bad args:\nCorrect usage: ./RTv1 [scene]");
	initiate(&env.mlx, "RTv1");
	parse(&env.scene, argv[1]);
	int i = -1;
	while (++i < env.scene.n_obj)
	printf("%s\nRadius: %lf Col: %x Radius2: %lf\n", argv[1], env.scene.obj[i].r, env.scene.obj[i].col, env.scene.obj[i].r2);
	make_image(&env.mlx, env.scene.obj);
	mlx_put_image_to_window(env.mlx.mlx, env.mlx.win, env.mlx.img, 0, 0);
	mlx_hook(env.mlx.win, 2, 0L, key_add, env.keys);
	mlx_hook(env.mlx.win, 4, 0L, mouse_add, &env.mouse);
	mlx_hook(env.mlx.win, 5, 0L, mouse_remove, &env.mouse);
	mlx_hook(env.mlx.win, 6, 0L, mouse_hook, &env.mouse);
	mlx_key_hook(env.mlx.win, key_remove, env.keys);
	mlx_hook(env.mlx.win, 17, 0L, close_hk, &env);
	mlx_loop_hook(env.mlx.mlx, key_hk, &env);
	mlx_loop(env.mlx.mlx);
	return (0);
}
