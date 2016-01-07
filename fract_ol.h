/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:04:50 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/19 15:04:51 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "X11/X.h"

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_var
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		tmp;
	int				i;
}					t_var;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*am;
	int				height;
	int				width;
	int				bpp;
	int				i_max;
	t_var			v;
	double			x1;
	double			y1;
	int				fractal;
	long double		zoom;
	long double		xm;
	long double		ym;
	long double		cx;
	long double		cy;
	int				stop;
	int				sl;
	int				endian;
}					t_env;

void				verif(char *s1, t_env *e, int c);
int					expose_hook(t_env *e);
int					couleur(double i);
void				pixel_put_image(t_env *e, int x, int y, unsigned int c);
int					mouse_hook(int button, int x, int y, t_env *e);
int					event_mouse(int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
void				madelbrot(int x, int y, t_env *e);
void				julia(int x, int y, t_env *e);
void				dentrite(int x, int y, t_env *e);

#endif
