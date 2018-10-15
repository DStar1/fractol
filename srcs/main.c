/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:25:43 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/14 18:07:16 by hasmith          ###   ########.fr       */
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
	// mlx_destroy_image(m->mlx, m->img_ptr);
}


//////////////////

int		my_key_funct(int keycode, t_mlx *mast)
{
	(void)mast;
	if (keycode == 53)
		exit(1);
	return (0);
}

void pixel_put(t_mlx *mlx, int x, int y, int color){
	if (x < mlx->wsize && y < mlx->wsize)
		if (y >= 0 && x >= 0)
			mlx->img_int[((y * mlx->wsize) + x)] = color;
}

void julia(t_mlx *mast){
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*mast->wsize/mast->wsize;
	double Re_factor = (MaxRe-MinRe)/(mast->wsize-1);
	double Im_factor = (MaxIm-MinIm)/(mast->wsize-1);
	int MaxIterations = 30;

	for(int y=0; y<mast->wsize; ++y)
	{
		double c_im = MaxIm - y*Im_factor;
		for(int x=0; x<mast->wsize; ++x)
		{
			double c_re = MinRe + x*Re_factor;

			double Z_re = c_re, Z_im = c_im;
			int isInside = 1;
			for(int n=0; n<MaxIterations; ++n)
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
	}
}

int		main(int argc, char *argv[])
{
	t_mlx	mast;

	ft_bzero(&mast, sizeof(mast));
	mast.wsize = 1000;
	mast.mlx = mlx_init();
	mast.win = mlx_new_window(mast.mlx, mast.wsize, mast.wsize, "FRACTOL");
	// pixel_str(&mast);

	// put_new_map(&mast);
	pixel_str(&mast);//new
	julia(&mast);
	create_image(&mast);//new

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

	mlx_hook(mast.win, 2, 0, my_key_funct, &mast);
	// mlx_do_sync(mast.mlx);
	mlx_loop(mast.mlx);
	// mlx_destroy_image(mast.mlx, mast.img_ptr);
	sleep(3);
	return (argc);
}
