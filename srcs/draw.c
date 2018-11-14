/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/14 01:16:22 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			pixel_put(t_fract *mlx, int x, int y, int color)
{
	int i;

	if (x < mlx->wsize && y < mlx->wsize)
	{
		i = (x) + (y * mlx->size_line / 4);
		mlx->img_int[i] = color;
		mlx->img_int[++i] = color >> 8;
		mlx->img_int[++i] = color >> 16;
	}
}

/*
** Muti-threading
*/

static void		*draw_in_thread(void *arg)
{
	t_thread	*thread;
	t_fract		*mast;
	int			height;
	int			y;

	thread = (t_thread*)arg;
	mast = thread->m;
	height = (thread->count * (mast->height / 4)) + (mast->height / 4);
	y = (mast->height / 4) * thread->count;
	while (y < height)
	{
		if (mast->frac == 1)
			mandelbrot(mast, y);
		else if (mast->frac == 2)
			julia(mast, y);
		else if (mast->frac == 3)
			mandelchick(mast, y);
		++y;
	}
	return (mast);
}

void			draw_frac(t_fract *mast)
{
	int			i;
	t_thread	*thread;
	pthread_t	tid[4];

	i = -1;
	ft_bzero(mast->img_int, mast->width * mast->height * 4);
	thread = ft_memalloc(sizeof(t_thread) * 4);
	while (++i < 4)
	{
		thread[i].m = mast;
		thread[i].count = i;
		pthread_create(&tid[i], NULL, draw_in_thread, &thread[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(tid[i], NULL);
	create_image(mast);
	free(thread);
}
