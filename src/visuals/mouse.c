/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:40:36 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/10 17:43:29 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuals.h"

int	mouse_hook(int x, int y, t_mouse *mouse)
{
	mouse->pos[0] = x;
	mouse->pos[1] = y;
	return (0);
}

int mouse_add(int button, int x, int y, t_mouse *mouse)
{
	if (button == 1)
		mouse->left = 1;
	if (button == 2)
		mouse->right = 1;
	return (x + y);
}

int mouse_remove(int button, int x, int y, t_mouse *mouse)
{
	if (button == 1)
		mouse->left = 0;
	if (button == 2)
		mouse->right = 0;
	return (x + y);
}
