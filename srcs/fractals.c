/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:13:12 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/13 21:17:07 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void mandelbrot(t_mlx *mast, int y){
	double c_im;
	double c_re;
	int n;
	double Z_re2;
	double Z_im2;
	double Z_re;
	double Z_im;

	c_im = mast->maxIm - (y * mast->im_factor) / mast->zoom;
	for(int x=0; x<mast->width; ++x)
	{
		c_re = mast->minRe + (x * mast->re_factor) / mast->zoom;
		Z_re = c_re;
		Z_im = c_im;
		for(n=0; n<mast->maxIterations; ++n)
		{
			Z_re2 = Z_re*Z_re;
			Z_im2 = Z_im*Z_im;
			if(Z_re2 + Z_im2 > 4)
				break;
			Z_im = 2*Z_re*Z_im + c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
		}
		if (n < mast->maxIterations)
			psychedelic(mast, x, y, n);
		else
			pixel_put(mast, x, y, 0x990000);
	}
}

void julia(t_mlx *mast, int y){
	double c_im;
	double c_re;
	int n;
	double Z_re2;
	double Z_im2;
	double Z_re;
	double Z_im;

	if (mast->space % 2 != 0){
		c_im = mast->mouse_y * mast->im_factor;
		c_re = mast->mouse_x * mast->re_factor;
	}
	else{
		c_im = (mast->mouse_y * mast->im_factor) / mast->zoom;
		c_re = (mast->mouse_x * mast->re_factor) / mast->zoom;
	}
	for(int x=0; x<mast->width; ++x)
	{
		Z_re = mast->minRe + (x * mast->re_factor)/mast->zoom;
		Z_im = mast->maxIm - (y * mast->im_factor)/mast->zoom;
		for(n=0; n<mast->maxIterations; ++n)
		{
			Z_re2 = Z_re*Z_re;
			Z_im2 = Z_im*Z_im;
			if(Z_re2 + Z_im2 > 4)
				break;
			Z_im = 2*Z_re*Z_im + c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
		}
		if (n < mast->maxIterations)
			psychedelic(mast, x, y, n);
		else
			pixel_put(mast, x, y, 0x990000);
	}
}


void mandelchick(t_mlx *mast, int y){
		int n;
		double c_im = mast->maxIm - (y*mast->im_factor);
		for(int x=0; x<mast->wsize; ++x)
		{
			double c_re = mast->minRe + x*mast->re_factor;

			double Z_re = c_re, Z_im = c_im;
			for(n=0; n<mast->maxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re/mast->zoom;
				double Z_im2 = Z_im*Z_im/mast->zoom;
				if(Z_re2 + Z_im2 > 4)
					break;
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if (n < mast->maxIterations)
				psychedelic(mast, x, y, n);
			else
				pixel_put(mast, x, y, 0x990000);
		}
}

/*
void mandelbrot1(t_mlx *mast, int y){
	// mast->maxIm = mast->minIm+(mast->maxRe-mast->minRe)*mast->wsize/mast->wsize;
	// mast->re_factor = (mast->maxRe-mast->minRe)/(0.5 * mast->zoom * mast->wsize-1);// -(mast->move_x*100);//move_x?
	// mast->im_factor = (mast->maxIm-mast->minIm)/(0.5 * mast->zoom * mast->wsize-1);// -(mast->move_y*100);//move_y?

	// for(int y=0; y<mast->wsize; ++y)
	// {
		// printf("INNNNNNN\n");
		int n;
		double c_im = mast->maxIm - (y*mast->im_factor) / mast->zoom;
		for(int x=0; x<mast->wsize; ++x)
		{
			double c_re = (mast->minRe + x*mast->re_factor)/mast->zoom;
			// double Z_re = mast->minRe + (x * mast->re_factor)/mast->zoom;
			// double Z_im = mast->maxIm - (y * mast->im_factor)/mast->zoom;

			double Z_re = c_re;
			double Z_im = c_im;
			int isInside = 1;
			for(n=0; n<mast->maxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if (n < mast->maxIterations){
				//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
				// color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
				psychedelic(mast, x, y, n);
			}
			if(isInside) {
				// psychedelic(mast, x, y, i)
				pixel_put(mast, x, y, 0x990000);
			}
			// pixel_put(mast, 600, 600, 0xFF0000);
			// pixel_put(mast, 601, 599, 0xFF0000);
			// pixel_put(mast, 599, 601, 0xFF0000);
			// pixel_put(mast, 601, 601, 0xFF0000);
			// pixel_put(mast, 599, 599, 0xFF0000);
		}
}
*/