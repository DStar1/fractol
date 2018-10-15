/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:27 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/14 20:15:30 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_mlx
{
	int				*img_int;
	void			*mlx_ptr;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	void			*mlx;
	void			*win;

	int				wsize;
	int				height;
	int				width;
	int		mouse_x;
	int		mouse_y;
	int		mouse_left_x;
	int		mouse_left_y;
	int		mouse_right_x;
	int		mouse_right_y;

	double			minRe;
	double			maxRe;
	double			minIm;
	double			maxIm;
	double			re_factor;
	double			im_factor;
	int				maxIterations;

	double			zoom;
	double				move_x;
	double		move_y;




}					t_mlx;

void				draw(t_mlx *master, int y1, int x1, int color);
void				put_new_map(t_mlx *mlx);
void				pixel_str(t_mlx *m);
void draw_frac(t_mlx *mast, int frac);


void	move_up(t_mlx *v);
void	move_down(t_mlx *v);
void	move_right(t_mlx *v);
void	move_left(t_mlx *v);
int		key_press_hook(int keycode, t_mlx *mast);
int		mouse_motion_hook(int x, int y, t_mlx *m);
void move_xy(t_mlx *mast);

#endif 
