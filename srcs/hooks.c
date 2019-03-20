/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:48:41 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/15 00:52:48 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Key hooks
*/

int			key_press_hook(int keycode, t_fract *m)
{
	if (keycode == EXIT_KEY)
		exit(1);
	else if (keycode == UP)
		move_up(m);
	else if (keycode == DOWN)
		move_down(m);
	else if (keycode == RIGHT)
		move_right(m);
	else if (keycode == LEFT)
		move_left(m);
	else if (keycode == MINUS)
		m->max_iterations += 1;
	else if (keycode == PLUS)
		m->max_iterations -= 1;
	else if (keycode == SPACE)
		m->h.space += 1;
	else if (keycode == R_KEY)
		init(m);
	else
		color_hooks(keycode, m);
	move_xy(m);
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
		m->h.zoom /= 1.25;
		m->min_re += ((x - (m->width / 2) + (75 / 1.25))
						* m->re_factor) / m->h.zoom;
		m->max_re += ((x - (m->width / 2) + (75 / 1.25))
						* m->re_factor) / m->h.zoom;
		m->min_im -= ((y - (m->height / 2) + (75 / 1.25))
						* m->im_factor) / m->h.zoom;
		m->max_im -= ((y - (m->height / 2) + (75 / 1.25))
						* m->im_factor) / m->h.zoom;
		draw_frac(m);
	}
	if (code == 5)
	{
		draw_frac(m);
		m->h.zoom *= 1.25;
		m->min_re += ((x - (m->width / 2) + 75) * m->re_factor) / m->h.zoom;
		m->max_re += ((x - (m->width / 2) + 75) * m->re_factor) / m->h.zoom;
		m->min_im -= ((y - (m->height / 2) + 75) * m->im_factor) / m->h.zoom;
		m->max_im -= ((y - (m->height / 2) + 75) * m->im_factor) / m->h.zoom;
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
	if (m->frac == 2 && m->h.space % 2 == 0)
	{
		m->h.mouse_x = x / 2 - (m->width / 2);
		m->h.mouse_y = y / 2 - (m->height / 2);
		draw_frac(m);
	}
	return (1);
}

void		set_hooks(t_fract *m)
{
	mlx_hook(m->mlx_s.win, 2, 0, key_press_hook, m);
	mlx_hook(m->mlx_s.win, 4, 0, mouse_press_hook, m);
	mlx_hook(m->mlx_s.win, 6, 0, mouse_motion_hook, m);
}
