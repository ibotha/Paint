/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:39:16 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/10 17:29:48 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUALS_H
# define FT_VISUALS_H

# include <mlx.h>
# include "die.h"
# include "objects.h"

# define WIN_W 640
# define WIN_H 480

# define ABS(C) (C < 0 ? -C : C)
# define DR(N) (change < 0 ? (-N) : N)
# define ALP(C) ((float)(C & 0xff000000) / 0xff000000)
# define ALP_I(C) ((float)(C & 0xff000000) / 0x01000000)
# define RED(C) ((C & 0x00ff0000) / 0x00010000)
# define GRN(C) ((C & 0x0000ff00) / 0x00000100)
# define BLU(C) (C & 0x000000ff)

typedef	int		t_xy[2];

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*img_buff;
	int				bpp;
	int				ll;
	int				end;
	int				height;
	int				width;
}				t_mlx;
typedef enum	e_key
{
	init = -1,
	esc = 53,
	up = 126,
	down = 125,
	left = 123,
	right = 124,
	plus = 69,
	minus = 78,
	home = 115,
	end = 119,
	p_left = 86,
	p_right = 88,
	p_up = 91,
	p_down = 84,
	shift = 257,
	key_red = 15,
	key_green = 5,
	key_blue = 11,
	key_alpha = 0,
	ctrl = 256
}				t_key;

typedef	struct	s_mouse
{
	char	left;
	char	right;
	t_xy	pos;
}				t_mouse;

typedef struct	s_env
{
	t_mouse	mouse;
	char	keys[512];
	t_mlx	mlx;
	t_scene	scene;
}				t_env;

void	initiate(t_mlx	*mlx, char *title);
int		close_hk(t_env *env);
int		key_hk(t_env *env);
int		key_add(int keycode, char *keys);
int		mouse_hook(int x, int y, t_mouse *mouse);
int		mouse_add(int button, int x, int y, t_mouse *mouse);
int		mouse_remove(int button, int x, int y, t_mouse *mouse);
int		key_remove(int keycode, char *keys);
void	draw_line(t_xy a, t_xy b, int c, t_mlx *mlx);
void	draw_box(t_xy start, t_xy dim, int c, t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int c, int x, int y);
void	make_image(t_mlx *mlx, t_obj *obj);

#endif
