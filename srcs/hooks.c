/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:48:41 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/15 18:08:03 by hasmith          ###   ########.fr       */
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

int		mouse_press_hook(int code, int x, int y, t_mlx *m){
	if (code == 1)
	{
		draw_frac(m);
		m->minRe += ((x - (m->width/2))  * m->re_factor);// / v->zoom;
		m->maxRe += ((x - (m->width/2)) * m->re_factor);// / v->zoom;
		m->minIm -= ((y - (m->height/2))  * m->im_factor);// / v->zoom;
		m->maxIm -= ((y - (m->height/2)) * m->im_factor);// / v->zoom;
		//v->reFactor = (v->maxRe - v->minRe) / v->width;
		//v->imFactor = (v->maxIm - v->minIm) / v->width;
		draw_frac(m);
	}
	/* ZOOM OUT */
	if (code == 4)
	{
		draw_frac(m);
		m->zoom /= 1.25;
		m->minRe += ((x - (m->width/2))  * m->re_factor);// / v->zoom;
		m->maxRe += ((x - (m->width/2)) * m->re_factor);// / v->zoom;
		m->minIm -= ((y - (m->height/2))  * m->im_factor);// / v->zoom;
		m->maxIm -= ((y - (m->height/2)) * m->im_factor);// / v->zoom;
		// //v->reFactor = (v->maxRe - v->minRe) / v->width;
		// //v->imFactor = (v->maxIm - v->minIm) / v->width;
		draw_frac(m);


		//v->minRe /= 1.25;// += (((x - 600)  * v->reFactor) / v->zoom) / 10;
		//v->maxRe /= 1.25;//+= (((x - 600) * v->reFactor) / v->zoom) / 10;
		//v->minIm /= 1.25;//-= (((y - 600)  * v->imFactor) / v->zoom) / 10;
		//v->maxIm /= 1.25;//-= (((y - 600) * v->imFactor) / v->zoom) / 10;
		//v->reFactor = (v->maxRe - v->minRe) / v->width;
		//v->imFactor = (v->maxIm - v->minIm) / v->height;
		// draw_frac(m);
	}
	/* ZOOM IN */
	if (code == 5)
	{
		// draw_frac(m);
		m->zoom *= 1.25;
		// m->minRe += ((x - (m->width/2))  * m->re_factor);// / v->zoom;
		// m->maxRe += ((x - (m->width/2)) * m->re_factor);// / v->zoom;
		// m->minIm -= ((y - (m->height/2))  * m->im_factor);// / v->zoom;
		// m->maxIm -= ((y - (m->height/2)) * m->im_factor);// / v->zoom;
		// //v->reFactor = (v->maxRe - v->minRe) / v->width;
		// //v->imFactor = (v->maxIm - v->minIm) / v->width;
		draw_frac(m);

		//v->minRe *= 1.25;//+= (((x - 600)  * v->reFactor) / v->zoom) / 10;
		//v->maxRe *= 1.25;//+= (((x - 600) * v->reFactor)/ v->zoom) / 10;
		//v->minIm *= 1.25;//-= (((y - 600)  * v->imFactor) / v->zoom) / 10;
		//v->maxIm *= 1.25;//-= (((y - 600) * v->imFactor) / v->zoom) / 10;
		//v->reFactor = (v->maxRe - v->minRe) / v->width;
		//v->imFactor = (v->maxIm - v->minIm) / v->height;
		// draw_frac(m);

	}
	return (0);
}

// int			mouse_release_hook(int x, int y, t_mlx *m){
	
// }

int			mouse_motion_hook(int x, int y, t_mlx *m)
{
	if (m->frac == 2)
	{
		m->mouse_x = x/10-(m->width/10);
		m->mouse_y = y/10-(m->height/10);
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