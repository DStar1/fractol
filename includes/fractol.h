/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:27 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/14 01:35:46 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>

/*
	if (keycode == 53)//exit
	else if (keycode == 126)//up
	else if (keycode == 125)//down
	else if (keycode == 124)//right
	else if (keycode == 123)//left
	else if (keycode == 69)//minus
	else if (keycode == 78)//plus
	else if (keycode == 49)//space
	else if (keycode == 8)// c
	else if (keycode == 83)//1
	else if (keycode == 84)//2
	else if (keycode == 85)//3
	else if (keycode == 86)//4
	else if (keycode == 87)//5
	else if (keycode == 88)//6
	else if (keycode == 15)//r = reset

	// ZOOM OUT
	// if (code == 4)
	// ZOOM IN 
	// if (code == 5)

*/

typedef	struct		s_sets
{
	// double			min_re;
	// double			max_re;
	// double			min_im;
	// double			max_im;
	// double			re_factor;
	// double			im_factor;
	// int				max_iterations;

	double			c_im;
	double			c_re;
	int				n;
	double			Z_re2;
	double			Z_im2;
	double			Z_re;
	double			Z_im;
}					t_sets;

typedef struct		s_fract
{
	int				*img_int;
	void			*mlx_ptr;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	void			*mlx;
	void			*win;
	int				frac;
	int				toggle;
	int				space;
	int				wsize;
	int				height;
	int				width;
	int				mouse_x;
	int				mouse_y;
	int				mouse_left_x;
	int				mouse_left_y;
	int				mouse_right_x;
	int				mouse_right_y;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			re_factor;
	double			im_factor;
	int				max_iterations;
	// double			c_im;
	// double			c_re;
	// int				n;
	// double			Z_re2;
	// double			Z_im2;
	// double			Z_re;
	// double			Z_im;
	int				color_shift;
	int				color;
	int				color_change;
	double			zoom;
	double			move_x;
	double			move_y;
	t_sets			*s;
}					t_fract;

typedef	struct		s_thread
{
	t_fract			*m;
	int				count;
}					t_thread;

void				create_image(t_fract *m);
void				draw(t_fract *master, int y1, int x1, int color);
void				put_new_map(t_fract *mlx);
void				pixel_str(t_fract *m);
void				draw_frac(t_fract *mast);
void				set_hooks(t_fract *m);
void				move_up(t_fract *v);
void				move_down(t_fract *v);
void				move_right(t_fract *v);
void				move_left(t_fract *v);
int					key_press_hook(int keycode, t_fract *mast);
int					mouse_motion_hook(int x, int y, t_fract *m);
int					mouse_press_hook(int code, int x, int y, t_fract *m);
void				move_xy(t_fract *mast);
void				mandelbrot(t_fract *mast, int y);
void				julia(t_fract *mast, int y);
void				pixel_put(t_fract *mlx, int x, int y, int color);
void				psychedelic(t_fract *m, int x, int y, int i);
void				init(t_fract *m);
void				mandelchick(t_fract *mast, int y);
void				color_shift(t_fract *mast);

#endif
