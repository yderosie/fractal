/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:04:35 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/19 15:04:41 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	pixel_put_image(t_env *e, int x, int y, unsigned int c)
{
	int i;
	int j;
	int b;

	i = x * e->bpp / 8;
	j = y * e->sl;
	b = (c & 0xFF) >> 0;
	e->am[i + j] = b;
	b = (c & 0xFF00) >> 8;
	e->am[i + j + 1] = b;
	b = (c & 0xFF0000) >> 16;
	e->am[i + j + 2] = b;
}

int		couleur(double i)
{
	return ((RGB(127.5 * (1 + cos(i)),
	127.5 * (1 + sin(i)),
	127.5 * (1 - cos(i)))));
}

void	erreur(int i)
{
	i = 0;
	i += i;
	ft_putstr("Entrer en parametre le nom d'une des fractales suivante:\n");
	ft_putstr("-Mandelbrot\n-Julia\n-Dentrite\n");
}

void	verif(char *s1, t_env *e, int c)
{
	if (c == 2)
	{
		if (ft_strcmp(s1, "mandelbrot") == 0 ||
			ft_strcmp(s1, "Mandelbrot") == 0)
			e->fractal = 1;
		else if (ft_strcmp(s1, "julia") == 0 ||
			ft_strcmp(s1, "Julia") == 0)
			e->fractal = 2;
		else if (ft_strcmp(s1, "dentrite") == 0 ||
			ft_strcmp(s1, "Dentrite") == 0)
			e->fractal = 3;
	}
	else
		erreur(1);
}

int		main(int argc, char **argv)
{
	t_env e;

	e.fractal = 0;
	verif(argv[1], &e, argc);
	if (e.fractal != 0)
	{
		e.height = 800;
		e.width = 800;
		e.zoom = 1.0 / 256;
		e.ym = 0;
		e.xm = -0.5;
		e.stop = 0;
		e.i_max = 300;
		e.mlx = mlx_init(e.mlx);
		e.win = mlx_new_window(e.mlx, e.width, e.height, "fract_ol");
		e.img = mlx_new_image(e.mlx, e.width, e.height);
		e.am = mlx_get_data_addr(e.img, &e.bpp, &e.sl, &e.endian);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_key_hook(e.win, key_hook, &e);
		if (e.fractal == 2)
			mlx_hook(e.win, MotionNotify, PointerMotionMask, event_mouse, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
