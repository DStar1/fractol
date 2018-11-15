/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:09 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/15 00:43:01 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			pixel_put(t_fract *m, int x, int y, int color)
{
	int i;

	if (x < m->width && y < m->height)
	{
		i = (x) + (y * m->mlx_s.size_line / 4);
		m->mlx_s.img_int[i] = color;
		m->mlx_s.img_int[++i] = color >> 8;
		m->mlx_s.img_int[++i] = color >> 16;
	}
}

/*
** Muti-threading
*/

static void		*draw_in_thread(void *arg)
{
	t_thread	*thread;
	t_fract		*m;
	int			height;
	int			y;

	thread = (t_thread*)arg;
	m = thread->m;
	height = (thread->count * (m->height / 4)) + (m->height / 4);
	y = (m->height / 4) * thread->count;
	while (y < height)
	{
		if (m->frac == 1)
			mandelbrot(m, y);
		else if (m->frac == 2)
			julia(m, y);
		else if (m->frac == 3)
			mandelchick(m, y);
		++y;
	}
	return (m);
}

void			draw_frac(t_fract *m)
{
	int			i;
	t_thread	*thread;
	pthread_t	tid[4];

	i = -1;
	ft_bzero(m->mlx_s.img_int, m->width * m->height * 4);
	thread = ft_memalloc(sizeof(t_thread) * 4);
	while (++i < 4)
	{
		thread[i].m = m;
		thread[i].count = i;
		pthread_create(&tid[i], NULL, draw_in_thread, &thread[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(tid[i], NULL);
	create_image(m);
	free(thread);
}
