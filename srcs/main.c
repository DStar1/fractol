/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:25:43 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/14 20:30:16 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** creates a string with alocated space for all pixels on screen
*/

void	pixel_str(t_mlx *m)
{
	m->img_ptr = mlx_new_image(m->mlx, m->wsize, m->wsize);
	m->img_int = (int*)mlx_get_data_addr(
		m->img_ptr, &m->bpp, &m->size_line, &m->endian);
}

/*
** puts all pixles to screen, and then destroys the image
*/

static void	create_image(t_mlx *m)
{
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
	mlx_destroy_image(m->mlx, m->img_ptr);///maybe
}


//////////////////

void move_xy(t_mlx *mast){
	draw_frac(mast, 1);
}



void pixel_put(t_mlx *mlx, int x, int y, int color){
	if (x < mlx->wsize && y < mlx->wsize)
		if (y >= 0 && x >= 0)
			mlx->img_int[((y * mlx->wsize) + x)] = color;
}

void mandelbrot(t_mlx *mast, int y){
	// mast->maxIm = mast->minIm+(mast->maxRe-mast->minRe)*mast->wsize/mast->wsize;
	mast->re_factor = (mast->maxRe-mast->minRe)/(0.5 * mast->zoom * mast->wsize-1) + mast->move_x;//move_x?
	mast->im_factor = (mast->maxIm-mast->minIm)/(0.5 * mast->zoom * mast->wsize-1) + mast->move_y;//move_y?

	// for(int y=0; y<mast->wsize; ++y)
	// {
		double c_im = mast->maxIm - y*mast->im_factor;
		for(int x=0; x<mast->wsize; ++x)
		{
			double c_re = mast->minRe + x*mast->re_factor;

			double Z_re = c_re, Z_im = c_im;
			int isInside = 1;
			for(int n=0; n<mast->maxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(isInside) {
				pixel_put(mast, x, y, 0x990000);
			}
			// pixel_put(mast, 600, 600, 0xFF0000);
			// pixel_put(mast, 601, 599, 0xFF0000);
			// pixel_put(mast, 599, 601, 0xFF0000);
			// pixel_put(mast, 601, 601, 0xFF0000);
			// pixel_put(mast, 599, 599, 0xFF0000);
		}
	// }
}

void julia(t_mlx *mast, int y){
	mast->maxIm = mast->minIm+(mast->maxRe-mast->minRe)*mast->wsize/mast->wsize;
	mast->re_factor = (mast->maxRe-mast->minRe)/(0.5 * mast->zoom * mast->wsize-1) + mast->move_x;
	mast->im_factor = (mast->maxIm-mast->minIm)/(0.5 * mast->zoom * mast->wsize-1) + mast->move_y;

	// for(int y=0; y<mast->wsize; ++y)
	// {
		double c_im = mast->mouse_y * mast->im_factor;
		double c_re = mast->mouse_x * mast->re_factor;
		for(int x=0; x<mast->wsize; ++x)
		{
			double Z_re = mast->minRe + (x * mast->re_factor);// / v->zoom;
			double Z_im = mast->maxIm - (y * mast->im_factor);// / v->zoom;
		// z_re = mast->minRe + (x * mast->reFactor);// / v->zoom;
		// z_im = mast->maxIm - (y * mast->imFactor);// / v->zoom;

			int isInside = 1;
			for(int n=0; n<mast->maxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(isInside) {
				pixel_put(mast, x, y, 0x990000);
			}
			// pixel_put(mast, 600, 600, 0xFF0000);
			// pixel_put(mast, 601, 599, 0xFF0000);
			// pixel_put(mast, 599, 601, 0xFF0000);
			// pixel_put(mast, 601, 601, 0xFF0000);
			// pixel_put(mast, 599, 599, 0xFF0000);
		}
	// }
}

void draw_frac(t_mlx *mast, int frac){
	pixel_str(mast);//new
	if (frac == 1){
		for(int y=0; y<mast->wsize; ++y)
			mandelbrot(mast, y);
	}
	else if (frac == 2){
		for(int y=0; y<mast->wsize; ++y)
			julia(mast, y);
	}
	// for(int y=0; y<mast.wsize; ++y)
	// 	julia(&mast, y);
	create_image(mast);//new
}

void init(t_mlx *mast){
	mast->height = 1000;
	mast->width = 1000;
	mast->minRe = -2.0;
	mast->maxRe = 1.0;
	mast->minIm = -1.2;
	mast->maxIterations = 30;
	mast->zoom = 1;
	mast->maxIm = 2.0;

}

void		set_hooks(t_mlx *m)
{
	// mlx_hook(m->win, 12, 0, expose_hook, m);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	// mlx_hook(m->win, 3, 0, key_release_hook, m);
	// mlx_hook(m->win, 4, 0, mouse_press_hook, m);
	// mlx_hook(m->win, 5, 0, mouse_release_hook, m);

	mlx_hook(m->win, 6, 0, mouse_motion_hook, m);
	
	// mlx_hook(m->win, 17, 0, exit_hook, m);
}

int		main(int argc, char *argv[])
{
	t_mlx	mast;

	ft_bzero(&mast, sizeof(mast));
	mast.wsize = 1000;
	mast.mlx = mlx_init();
	mast.win = mlx_new_window(mast.mlx, mast.wsize, mast.wsize, "FRACTOL");

	mast.move_x = 0;//.1;
	mast.move_y = 0;//.1;
	init(&mast);

	draw_frac(&mast, 1);

	////////////////////////////
	// pixel_str(&mast);//new
	// for (int j = 0; j < 3;j++){
	// 	for (int i = j*2; i < (j*2)+10000;i++)
	// 		mast.img_int[i] = 0x990000;
	// 	create_image(&mast);//new
	// }
	////////////////////////////

	ft_printf("Project %s successfully created! \n", argv[0]);
	ft_putchar('\n');

	set_hooks(&mast);
	// mlx_hook(mast.win, 2, 0, my_key_funct, &mast);

	// mlx_do_sync(mast.mlx);
	mlx_loop(mast.mlx);
	// mlx_destroy_image(mast.mlx, mast.img_ptr);
	sleep(3);
	return (argc);
}
