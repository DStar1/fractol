/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:48:41 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/15 16:49:39 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int		key_press_hook(int keycode, t_mlx *mast)
{
	(void)mast;
	printf("KEYCODE:  %d\n", keycode);
	if (keycode == 53)//exit
		exit(1);
	else if (keycode == 126)//up
		move_up(mast);
	else if (keycode == 125)//down
		move_down(mast);
	else if (keycode == 124)//right
		move_right(mast);
	else if (keycode == 123)//left
		move_left(mast);
	else if (keycode == 69)//zoom in
		mast->zoom+=(mast->zoom*.01);
	else if (keycode == 78)//zoom out
		mast->zoom-=(mast->zoom*.01);
	move_xy(mast);
	return (0);
}

int			mouse_motion_hook(int x, int y, t_mlx *m)
{
	m->mouse_x = x/10-(m->width/10);
	m->mouse_y = y/10-(m->height/10);

    // printf("%d, %d\n", x,y);
    // move_xy(m);
	draw_frac(m);

	// if (x >= 0 && x < m->width && y >= 0 && y < m->height)// &&
	// 		//!m->togs->home && !m->togs->end)
	// {
	// 	draw_frac(m);
	// }


	// 	if (m->togs->mouse_left)
	// 	{
	// 		translate_xy(m, -(x - m->mouse_left_x) * DRAG_SENS,
	// 				-(y - m->mouse_left_y) * DRAG_SENS);
	// 		m->mouse_left_x += x - m->mouse_left_x;
	// 		m->mouse_left_y += y - m->mouse_left_y;
	// 	}
	// 	if (m->togs->mouse_right)
	// 	{
	// 		m->z_re += (x - m->mouse_right_x) * TRANS_SENS;
	// 		m->z_im += (y - m->mouse_right_y) * TRANS_SENS;
	// 		m->mouse_right_x += x - m->mouse_right_x;
	// 		m->mouse_right_y += y - m->mouse_right_y;
	// 		m->toggle = 1;
	// 	}
	// 	if (m->toggle)
	// 		start_draw(m);
	// }
	return (1);
}