/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/04/05 02:47:31 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// /*
// ** creates a string with alocated space for all pixels on screen
// */

// void	pixel_str(t_mlx *m)
// {
// 	m->img_ptr = mlx_new_image(m->mlx, m->wsize, m->wsize);
// 	m->img_int = (int*)mlx_get_data_addr(
// 		m->img_ptr, &m->bpp, &m->size_line, &m->endian);
// }

// /*
// ** puts all pixles to screen, and then destroys the image
// ** mlx_destroy_image(m->mlx, m->img_ptr); to destroy
// */

// void	create_image(t_mlx *m)
// {
// 	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
// }

// /*
// ** draws to screen map to screen
// */

// void	draw(t_mlx *mlx, int y1, int x1, int color)
// {
// 	int x;
// 	int y;
// 	int x_dist;
// 	int y_dist;

// 	y_dist = (mlx->wsize / mlx->mylen);
// 	x_dist = (mlx->wsize / mlx->mxlen);
// 	y = y1 * y_dist;
// 	while (y < ((y1 * y_dist) + y_dist))
// 	{
// 		x = x1 * x_dist;
// 		while (x < ((x1 * x_dist) + x_dist))
// 		{
// 			if (x < mlx->wsize && y < mlx->wsize)
// 				if (y >= 0 && x >= 0)
// 					if (x != x1 * x_dist && y != y1 * y_dist)
// 						mlx->img_int[((y * mlx->wsize) + x)] = color;
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	put_new_map(t_mlx *mlx)
// {
// 	int y;
// 	int x;

// 	y = 0;
// 	while (y < mlx->mylen)
// 	{
// 		x = 0;
// 		while (x < mlx->mxlen)
// 		{
// 			if (mlx->map[y][x] == mlx->player)
// 				draw(mlx, y, x, 0x000099);
// 			if (mlx->map[y][x] == mlx->opponent)
// 				draw(mlx, y, x, 0x990000);
// 			x++;
// 		}
// 		y++;
// 	}
// 	create_image(mlx);
// }
