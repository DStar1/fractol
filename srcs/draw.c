/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/15 17:09:53 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void pixel_put(t_mlx *mlx, int x, int y, int color){
	if (x < mlx->wsize && y < mlx->wsize)
		if (y >= 0 && x >= 0)
			mlx->img_int[((y * mlx->wsize) + x)] = color;
}

static void *draw_in_thread(void *arg){
	t_thread	*thread;
	t_mlx *mast;
	int height;
	int y;

	thread = (t_thread*)arg;
	mast = thread->m;
	height = (thread->count * (mast->height/4)) + (mast->height/4);
	y = (mast->height/4) * thread->count;
	// static int s = 0;
	// ++s;
	// printf("Pid: %d, Ppid: %d, s = %d\n", getpid(), getppid(), ++s);
	for(; y<height; ++y)
	{
		if (mast->frac == 1){
			// printf("Madelbrot\n");
			mandelbrot(mast, y);
		}
		else if (mast->frac == 2){
			// printf("Julia\n");
			// for(int y=0; y<mast->wsize; ++y)
			julia(mast, y);
		}
	}
	return(mast);
}

void draw_frac(t_mlx *mast){
	// mlx_destroy_image(mast->mlx, mast->img_ptr);
	// mlx_clear_window(mast->mlx, mast->win);

	int			i;
	t_thread	*thread;
	pthread_t	tid[4];

	i = -1;
	pixel_str(mast);
	thread = ft_memalloc(sizeof(t_thread) * 4);
	while (++i < 4)
	{
		thread[i].m = mast;
		thread[i].count = i;
		pthread_create(&tid[i], NULL, draw_in_thread, &thread[i]);
	}
	i = -1;
	while (++i < 4)
	{
		pthread_join(tid[i], NULL);
	}
	// mlx_clear_window(mast->mlx, mast->win);
	create_image(mast);//new
	free(thread);
}