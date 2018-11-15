/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:27 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/15 00:13:33 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define SQUARE(x) (x * x)
# define EXIT_KEY 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define MINUS 69
# define PLUS 78
# define SPACE 49
# define C_KEY 8
# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define SIX 88
# define R_KEY 15
# define ZOOM_OUT 4
# define ZOOM_IN 5


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
	double			z_re2;
	double			z_im2;
	double			z_re;
	double			z_im;
	int				n;
	int				x;
}					t_sets;

typedef	struct		s_colors
{
	int				full_spectrum[16];
	int				blue_brown[16];
	int				gray_scale[16];
	int				blossom[16];
	int				the_sun[16];
}					t_colors;

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

	int				color_shift;
	int				color;
	int				color_change;
	t_colors		c;
	double			zoom;
	double			zoom_freeze;
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
void				color_hooks(int keycode, t_fract *mast);

#endif
