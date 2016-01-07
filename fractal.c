/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:48:10 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/26 16:48:14 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	madelbrot(int x, int y, t_env *e)
{
	t_var v;

	v.i = 0;
	v.c_r = (x + e->x1 - e->width / 2) * e->zoom + e->xm;
	v.c_i = (y + e->y1 - e->height / 2) * e->zoom + e->ym;
	v.z_r = 0;
	v.z_i = 0;
	while (v.z_r * v.z_r + v.z_i * v.z_i < 4 && v.i < e->i_max)
	{
		v.tmp = v.z_r;
		v.z_r = v.z_r * v.z_r - v.z_i * v.z_i + v.c_r;
		v.z_i = 2 * v.tmp * v.z_i + v.c_i;
		v.i++;
	}
	if (v.i == e->i_max)
		pixel_put_image(e, x, y, 0x000000);
	else
		pixel_put_image(e, x, y, couleur(v.i));
}

void	julia(int x, int y, t_env *e)
{
	t_var v;

	v.i = 0;
	v.z_r = (x + e->x1 - e->width / 2) * e->zoom + e->xm;
	v.z_i = (y + e->y1 - e->height / 2) * e->zoom + e->ym;
	v.c_r = 0.285 + e->v.c_r;
	v.c_i = 0.01 + e->v.c_i;
	while (v.z_r * v.z_r + v.z_i * v.z_i < 4 && v.i < e->i_max)
	{
		v.tmp = v.z_r;
		v.z_r = v.z_r * v.z_r - v.z_i * v.z_i + v.c_r;
		v.z_i = 2 * v.tmp * v.z_i + v.c_i;
		v.i++;
	}
	if (v.i == e->i_max)
		pixel_put_image(e, x, y, 0x000000);
	else
		pixel_put_image(e, x, y, couleur(v.i));
}

void	dentrite(int x, int y, t_env *e)
{
	t_var v;

	v.i = 0;
	v.z_r = (x + e->x1 - e->width / 2) * e->zoom + e->xm;
	v.z_i = (y + e->y1 - e->height / 2) * e->zoom + e->ym;
	v.c_r = 0 + e->v.c_r;
	v.c_i = 1 + e->v.c_i;
	while (v.z_r * v.z_r + v.z_i * v.z_i < 4 && v.i < e->i_max)
	{
		v.tmp = v.z_r;
		v.z_r = v.z_r * v.z_r - v.z_i * v.z_i + v.c_r;
		v.z_i = 2 * v.tmp * v.z_i + v.c_i;
		v.i++;
	}
	if (v.i == e->i_max)
		pixel_put_image(e, x, y, 0x000000);
	else
		pixel_put_image(e, x, y, couleur(v.i));
}
