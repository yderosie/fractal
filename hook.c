/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:50:06 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/26 16:50:09 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 115)
	{
		if (e->stop == 0)
			e->stop = 1;
		else
			e->stop = 0;
	}
	if (keycode == 65307)
	{
		mlx_destroy_image(e->mlx, e->img);
		exit (0);
	}
	return (keycode);
}

int		event_mouse(int x, int y, t_env *e)
{
	if (e->stop == 0)
	{
		if (x < 400)
			e->v.c_r -= 0.0006;
		if (x >= 400)
			e->v.c_r += 0.0006;
		if (y < 400)
			e->v.c_i -= 0.0006;
		if (y >= 400)
			e->v.c_i += 0.0006;
	}
	expose_hook(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	e->xm += (x - e->width / 2) * e->zoom;
	e->ym += (y - e->height / 2) * e->zoom;
	if (button == 5)
	{
		e->zoom *= 2;
	}
	if (button == 4)
	{
		if (e->zoom > fabs(x) * 1e-16 && e->zoom > fabs(y) * 1e-16)
			e->zoom /= 2;
	}
	expose_hook(e);
	return (button);
}

int		expose_hook(t_env *e)
{
	int x;
	int y;

	e->y1 = 0;
	e->x1 = 0;
	y = 0;
	while (y < e->height)
	{
		x = 0;
		while (x < e->width)
		{
			if (e->fractal == 1)
				madelbrot(x, y, e);
			if (e->fractal == 2)
				julia(x, y, e);
			if (e->fractal == 3)
				dentrite(x, y, e);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
