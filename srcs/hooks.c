/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:48:41 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/13 21:10:25 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/*
** Key hooks
*/

int		key_press_hook(int keycode, t_mlx *mast)
{
	// (void)mast;
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
	else if (keycode == 69)//minus
		mast->maxIterations+=1;
	else if (keycode == 78)//plus
		mast->maxIterations-=1;
	else if (keycode == 49)//space
		mast->space += 1;
	else if (keycode == 8)// c
	{
		mast->color_shift += 1;
		if (mast->color_shift > 16)
			mast->color_shift = 0;
	}
	else if (keycode == 15)//r = reset
		init(mast);
	move_xy(mast);
	return (0);
}

/*
** Mouse hooks
*/

int		mouse_press_hook(int code, int x, int y, t_mlx *m){
	if (code == 1)
	{
		draw_frac(m);
		m->minRe += ((x - (m->width/2))  * m->re_factor);///10;// / m->zoom;
		m->maxRe += ((x - (m->width/2)) * m->re_factor);///10;// / m->zoom;
		m->minIm -= ((y - (m->height/2))  * m->im_factor);//10;// / m->zoom;
		m->maxIm -= ((y - (m->height/2)) * m->im_factor);///10;// / m->zoom;
		// m->re_factor = (m->maxRe - m->minRe) / m->width;
		// m->im_factor = (m->maxIm - m->minIm) / m->width;
		draw_frac(m);
	}
	/* ZOOM OUT */
	if (code == 4)
	{
		draw_frac(m);
		m->zoom /= 1.25;
		// m->minRe += ((x - (m->width/2))  * m->re_factor) / m->zoom;
		// m->maxRe += ((x - (m->width/2)) * m->re_factor)/ m->zoom;
		// m->minIm -= ((y - (m->height/2))  * m->im_factor) / m->zoom;
		// m->maxIm -= ((y - (m->height/2)) * m->im_factor) / m->zoom;
		m->minRe += ((x - (m->width/2)+(75/1.25))  * m->re_factor) / m->zoom;
		m->maxRe += ((x - (m->width/2)+(75/1.25)) * m->re_factor) / m->zoom;
		m->minIm -= ((y - (m->height/2)+(75/1.25))  * m->im_factor) / m->zoom;
		m->maxIm -= ((y - (m->height/2)+(75/1.25)) * m->im_factor) / m->zoom;
		// // m->re_factor = (m->maxRe - m->minRe) / m->width;
		// // m->im_factor = (m->maxIm - m->minIm) / m->width;
		draw_frac(m);


		//m->minRe /= 1.25;// += (((x - 600)  * m->re_factor)/10 / m->zoom) / 10;
		//m->maxRe /= 1.25;//+= (((x - 600) * m->re_factor)/10 / m->zoom) / 10;
		//m->minIm /= 1.25;//-= (((y - 600)  * m->im_factor)/10 / m->zoom) / 10;
		//m->maxIm /= 1.25;//-= (((y - 600) * m->im_factor)/10 / m->zoom) / 10;
		//m->re_factor = (m->maxRe - m->minRe) / m->width;
		//m->im_factor = (m->maxIm - m->minIm) / m->height;
		// draw_frac(m);
	}
	/* ZOOM IN */
	if (code == 5)
	{
		draw_frac(m);
		m->zoom *= 1.25;
		// m->minRe += ((x - (m->width/2))  * m->re_factor) / m->zoom;
		// m->maxRe += ((x - (m->width/2)) * m->re_factor) / m->zoom;
		// m->minIm -= ((y - (m->height/2))  * m->im_factor) / m->zoom;
		// m->maxIm -= ((y - (m->height/2)) * m->im_factor) / m->zoom;
		m->minRe += ((x - (m->width/2)+75)  * m->re_factor) / m->zoom;
		m->maxRe += ((x - (m->width/2)+75) * m->re_factor) / m->zoom;
		m->minIm -= ((y - (m->height/2)+75)  * m->im_factor) / m->zoom;
		m->maxIm -= ((y - (m->height/2)+75) * m->im_factor) / m->zoom;
		// // m->re_factor = (m->maxRe - m->minRe) / m->width;
		// // m->im_factor = (m->maxIm - m->minIm) / m->width;
		draw_frac(m);

		//m->minRe *= 1.25;//+= (((x - 600)  * m->re_factor)/10 / m->zoom) / 10;
		//m->maxRe *= 1.25;//+= (((x - 600) * m->re_factor)/10/ m->zoom) / 10;
		//m->minIm *= 1.25;//-= (((y - 600)  * m->im_factor)/10 / m->zoom) / 10;
		//m->maxIm *= 1.25;//-= (((y - 600) * m->im_factor)/10 / m->zoom) / 10;
		//m->re_factor = (m->maxRe - m->minRe) / m->width;
		//m->im_factor = (m->maxIm - m->minIm) / m->height;
		// draw_frac(m);

	}
	return (0);
}

// int			mouse_release_hook(int x, int y, t_mlx *m){
	
// }

int			mouse_motion_hook(int x, int y, t_mlx *m)
{
	if (m->frac == 2 && m->space % 2 == 0)
	{
		m->mouse_x = x/2-(m->width/2);
		m->mouse_y = y/2-(m->height/2);
		// m->mouse_x = x/10-(m->width/10);
		// m->mouse_y = y/10-(m->height/10);
		draw_frac(m);
	}
    // printf("%d, %d\n", x,y);
    // move_xy(m);
	

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

void		set_hooks(t_mlx *m)
{
	// mlx_hook(m->win, 12, 0, expose_hook, m);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	// mlx_hook(m->win, 3, 0, key_release_hook, m);
	mlx_hook(m->win, 4, 0, mouse_press_hook, m);
	// mlx_hook(m->win, 5, 0, mouse_release_hook, m);

	mlx_hook(m->win, 6, 0, mouse_motion_hook, m);
	
	// mlx_hook(m->win, 17, 0, exit_hook, m);
}