/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:13:12 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/15 00:51:13 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_sets		*intit_fract_vars(t_fract *m)
{
	t_sets	*f_vars;

	(void)m;
	f_vars = ft_memalloc(sizeof(t_sets));
	f_vars->c_im = 0;
	f_vars->c_re = 0;
	f_vars->z_re2 = 0;
	f_vars->z_im2 = 0;
	f_vars->z_re = 0;
	f_vars->z_im = 0;
	f_vars->x = -1;
	f_vars->n = 0;
	return (f_vars);
}

void		mandelbrot(t_fract *m, int y)
{
	t_sets	*f_vars;

	f_vars = intit_fract_vars(m);
	f_vars->c_im = m->max_im - (y * m->im_factor) / m->h.zoom;
	while (++(f_vars->x) < m->width)
	{
		f_vars->c_re = m->min_re + (f_vars->x * m->re_factor) / m->h.zoom;
		f_vars->z_re = f_vars->c_re;
		f_vars->z_im = f_vars->c_im;
		f_vars->n = -1;
		while (++f_vars->n < m->max_iterations)
		{
			f_vars->z_re2 = f_vars->z_re * f_vars->z_re;
			f_vars->z_im2 = f_vars->z_im * f_vars->z_im;
			if (f_vars->z_re2 + f_vars->z_im2 > 4)
				break ;
			f_vars->z_im = (2 * f_vars->z_re * f_vars->z_im) + f_vars->c_im;
			f_vars->z_re = f_vars->z_re2 - f_vars->z_im2 + f_vars->c_re;
		}
		if (f_vars->n < m->max_iterations)
			psychedelic(m, f_vars->x, y, f_vars->n);
		else
			pixel_put(m, f_vars->x, y, 0x000000);
	}
	free(f_vars);
}

void		julia_help(t_fract *m, t_sets **f_vars)
{
	if (m->h.space % 2 != 0)
	{
		(*f_vars)->c_im = (m->h.mouse_y * m->im_factor) / m->h.z_freeze;
		(*f_vars)->c_re = (m->h.mouse_x * m->re_factor) / m->h.z_freeze;
	}
	else
	{
		(*f_vars)->c_im = (m->h.mouse_y * m->im_factor) / m->h.zoom;
		(*f_vars)->c_re = (m->h.mouse_x * m->re_factor) / m->h.zoom;
		m->h.z_freeze = m->h.zoom;
	}
}

void		julia(t_fract *m, int y)
{
	t_sets	*f_vars;

	f_vars = intit_fract_vars(m);
	julia_help(m, &f_vars);
	while (++(f_vars->x) < m->width)
	{
		f_vars->z_re = m->min_re + (f_vars->x * m->re_factor) / m->h.zoom;
		f_vars->z_im = m->max_im - (y * m->im_factor) / m->h.zoom;
		f_vars->n = -1;
		while (++f_vars->n < m->max_iterations)
		{
			f_vars->z_re2 = f_vars->z_re * f_vars->z_re;
			f_vars->z_im2 = f_vars->z_im * f_vars->z_im;
			if (f_vars->z_re2 + f_vars->z_im2 > 4)
				break ;
			f_vars->z_im = (2 * f_vars->z_re * f_vars->z_im) + f_vars->c_im;
			f_vars->z_re = f_vars->z_re2 - f_vars->z_im2 + f_vars->c_re;
		}
		if (f_vars->n < m->max_iterations)
			psychedelic(m, f_vars->x, y, f_vars->n);
		else
			pixel_put(m, f_vars->x, y, 0x000000);
	}
	free(f_vars);
}

void		mandelchick(t_fract *m, int y)
{
	t_sets	*f_vars;

	f_vars = intit_fract_vars(m);
	f_vars->c_im = m->max_im - (y * m->im_factor);
	while (++(f_vars->x) < m->width)
	{
		f_vars->c_re = m->min_re + f_vars->x * m->re_factor;
		f_vars->z_re = f_vars->c_re;
		f_vars->z_im = f_vars->c_im;
		f_vars->n = -1;
		while (++f_vars->n < m->max_iterations)
		{
			f_vars->z_re2 = f_vars->z_re * f_vars->z_re / m->h.zoom;
			f_vars->z_im2 = f_vars->z_im * f_vars->z_im / m->h.zoom;
			if (f_vars->z_re2 + f_vars->z_im2 > 4)
				break ;
			f_vars->z_im = 2 * f_vars->z_re * f_vars->z_im + f_vars->c_im;
			f_vars->z_re = f_vars->z_re2 - f_vars->z_im2 + f_vars->c_re;
		}
		if (f_vars->n < m->max_iterations)
			psychedelic(m, f_vars->x, y, f_vars->n);
		else
			pixel_put(m, f_vars->x, y, 0x000000);
	}
	free(f_vars);
}
