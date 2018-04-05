/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:27 by hasmith           #+#    #+#             */
/*   Updated: 2018/04/05 02:50:58 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../minilibx/mlx.h"
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
}					t_mlx;

void				draw(t_mlx *master, int y1, int x1, int color);
void				pixel_str(t_mlx *m);

#endif 
