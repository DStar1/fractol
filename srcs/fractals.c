/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:13:12 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/15 15:17:47 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

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