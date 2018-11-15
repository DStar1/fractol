/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:48:41 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/14 23:51:34 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Key hooks
*/

int			key_press_hook(int keycode, t_fract *mast)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 126)
		move_up(mast);
	else if (keycode == 125)
		move_down(mast);
	else if (keycode == 124)
		move_right(mast);
	else if (keycode == 123)
		move_left(mast);
	else if (keycode == 69)
		mast->max_iterations += 1;
	else if (keycode == 78)
		mast->max_iterations -= 1;
	else if (keycode == 49)
		mast->space += 1;
	else if (keycode == 15)
		init(mast);
	else
		color_hooks(keycode, mast);
	move_xy(mast);
	return (0);
}

/*
** Mouse hooks
*/

int			mouse_zoom_hook(int code, int x, int y, t_fract *m)
{
	if (code == 4)
	{
		draw_frac(m);
		m->zoom /= 1.25;
		m->min_re += ((x - (m->width / 2) + (75 / 1.25))
						* m->re_factor) / m->zoom;
		m->max_re += ((x - (m->width / 2) + (75 / 1.25))
						* m->re_factor) / m->zoom;
		m->min_im -= ((y - (m->height / 2) + (75 / 1.25))
						* m->im_factor) / m->zoom;
		m->max_im -= ((y - (m->height / 2) + (75 / 1.25))
						* m->im_factor) / m->zoom;
		draw_frac(m);
	}
	if (code == 5)
	{
		draw_frac(m);
		m->zoom *= 1.25;
		m->min_re += ((x - (m->width / 2) + 75) * m->re_factor) / m->zoom;
		m->max_re += ((x - (m->width / 2) + 75) * m->re_factor) / m->zoom;
		m->min_im -= ((y - (m->height / 2) + 75) * m->im_factor) / m->zoom;
		m->max_im -= ((y - (m->height / 2) + 75) * m->im_factor) / m->zoom;
		draw_frac(m);
	}
	return (0);
}

int			mouse_press_hook(int code, int x, int y, t_fract *m)
{
	if (code == 1)
	{
		draw_frac(m);
		m->min_re += ((x - (m->width / 2)) * m->re_factor);
		m->max_re += ((x - (m->width / 2)) * m->re_factor);
		m->min_im -= ((y - (m->height / 2)) * m->im_factor);
		m->max_im -= ((y - (m->height / 2)) * m->im_factor);
		draw_frac(m);
	}
	mouse_zoom_hook(code, x, y, m);
	return (0);
}

int			mouse_motion_hook(int x, int y, t_fract *m)
{
	if (m->frac == 2 && m->space % 2 == 0)
	{
		m->mouse_x = x / 2 - (m->width / 2);
		m->mouse_y = y / 2 - (m->height / 2);
		draw_frac(m);
	}
	return (1);
}

void		set_hooks(t_fract *m)
{
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	mlx_hook(m->win, 4, 0, mouse_press_hook, m);
	mlx_hook(m->win, 6, 0, mouse_motion_hook, m);
}
