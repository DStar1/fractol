/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:13:12 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/14 01:58:07 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void mandelbrot(t_fract *m, int y){
	double c_im;
	double c_re;
	int n;
	double Z_re2;
	double Z_im2;
	double Z_re;
	double Z_im;
	int x;

	c_im = m->max_im - (y * m->im_factor) / m->zoom;
	x = 0;
	while (x < m->width)
	{
		c_re = m->min_re + (x * m->re_factor) / m->zoom;
		Z_re = c_re;
		Z_im = c_im;
		n = 0;
		while (n < m->max_iterations)
		{
			Z_re2 = Z_re * Z_re;
			Z_im2 = Z_im * Z_im;
			if(Z_re2 + Z_im2 > 4)
				break;
			Z_im = (2 * Z_re * Z_im) + c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
			++n;
		}
		if (n < m->max_iterations)
			psychedelic(m, x, y, n);
		else
			pixel_put(m, x, y, 0x000000);
		++x;
	}
}

void julia(t_fract *m, int y){
	double c_im;
	double c_re;
	int n;
	double Z_re2;
	double Z_im2;
	double Z_re;
	double Z_im;
	int x;

	if (m->space % 2 != 0){
		c_im = m->mouse_y * m->im_factor;
		c_re = m->mouse_x * m->re_factor;
	}
	else{
		c_im = (m->mouse_y * m->im_factor) / m->zoom;
		c_re = (m->mouse_x * m->re_factor) / m->zoom;
	}
	x = 0;
	while (x < m->width)
	{
		Z_re = m->min_re + (x * m->re_factor) / m->zoom;
		Z_im = m->max_im - (y * m->im_factor) / m->zoom;
		n = 0;
		while (n < m->max_iterations)
		{
			Z_re2 = Z_re * Z_re;
			Z_im2 = Z_im * Z_im;
			if(Z_re2 + Z_im2 > 4)
				break;
			Z_im = (2 * Z_re * Z_im) + c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
			++n;
		}
		if (n < m->max_iterations)
			psychedelic(m, x, y, n);
		else
			pixel_put(m, x, y, 0x000000);
		++x;
	}
}


void mandelchick(t_fract *m, int y){
	double c_im;
	double c_re;
	int n;
	double Z_re2;
	double Z_im2;
	double Z_re;
	double Z_im;
	int x;

	c_im = m->max_im - (y * m->im_factor);
	x = 0;
	while (x < m->width)
	{
		c_re = m->min_re + x * m->re_factor;
		Z_re = c_re;
		Z_im = c_im;
		n = 0;
		while (n < m->max_iterations)
		{
			Z_re2 = Z_re * Z_re / m->zoom;
			Z_im2 = Z_im * Z_im / m->zoom;
			if(Z_re2 + Z_im2 > 4)
				break;
			Z_im = 2 * Z_re * Z_im + c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
			++n;
		}
		if (n < m->max_iterations)
			psychedelic(m, x, y, n);
		else
			pixel_put(m, x, y, 0x000000);
		++x;
	}
}

/*
void mandelbrot1(t_fract *m, int y){
	// m->max_im = m->min_im+(m->max_re-m->min_re)*m->wsize/m->wsize;
	// m->re_factor = (m->max_re-m->min_re)/(0.5 * m->zoom * m->wsize-1);// -(m->move_x*100);//move_x?
	// m->im_factor = (m->max_im-m->min_im)/(0.5 * m->zoom * m->wsize-1);// -(m->move_y*100);//move_y?

	// for(int y=0; y<m->wsize; ++y)
	// {
		// printf("INNNNNNN\n");
		int n;
		double c_im = m->max_im - (y*m->im_factor) / m->zoom;
		for(int x=0; x<m->wsize; ++x)
		{
			double c_re = (m->min_re + x*m->re_factor)/m->zoom;
			// double Z_re = m->min_re + (x * m->re_factor)/m->zoom;
			// double Z_im = m->max_im - (y * m->im_factor)/m->zoom;

			double Z_re = c_re;
			double Z_im = c_im;
			int isInside = 1;
			n = 0;
			while (n < m->max_iterations)
			{

				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
						++n;break;

				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if (n < m->max_iterations){
				//use color model conversion to get rainbow palette, make brightness black if max_iterations reached
				// color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < max_iterations)));
				psychedelic(m, x, y, n);
			}
			if(isInside) {
				// psychedelic(m, x, y, i)
				pixel_put(m, x, y, 0x990000);
			}
			// pixel_put(m, 600, 600, 0xFF0000);
			// pixel_put(m, 601, 599, 0xFF0000);
			// pixel_put(m, 599, 601, 0xFF0000);
			// pixel_put(m, 601, 601, 0xFF0000);
			// pixel_put(m, 599, 599, 0xFF0000);
		}
}
*/