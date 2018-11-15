/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:25:43 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/14 22:50:07 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** creates a string with alocated space for all pixels on screen
*/

void	pixel_str(t_fract *m)
{
	m->img_ptr = mlx_new_image(m->mlx, m->width, m->height);
	m->img_int = (int*)mlx_get_data_addr(
		m->img_ptr, &m->bpp, &m->size_line, &m->endian);
}

/*
** puts all pixles to screen, and then destroys the image
*/

void	create_image(t_fract *m)
{
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
}

void	move_xy(t_fract *m)
{
	draw_frac(m);
}

void	init(t_fract *m)
{
	m->height = 1000;
	m->width = 1000;
	m->min_re = -2.0;
	m->max_re = 2.0;
	m->min_im = -2;
	m->max_im = 2.0;
	m->max_iterations = 30;
	m->zoom = 1;
	m->re_factor = (m->max_re - m->min_re) / (m->width);
	m->im_factor = (m->max_im - m->min_im) / (m->height);
	m->min_re += (((m->width / 2) - (m->width / 2)) * m->re_factor);
	m->max_re += (((m->width / 2) - (m->width / 2)) * m->re_factor);
	m->min_im -= (((m->height / 2) - (m->height / 2)) * m->im_factor);
	m->max_im -= (((m->height / 2) - (m->height / 2)) * m->im_factor);
	m->space = 0;
	m->mouse_x = m->width / 2;
	m->mouse_y = m->height / 2;
	m->color = 1;
	m->color_shift = 0;
	m->color_change = 0xE0E907;
}

int		main(int argc, char *argv[])
{
	t_fract	*m;

	m = ft_memalloc(sizeof(t_fract));
	m->s = ft_memalloc(sizeof(t_sets));
	m->wsize = 1000;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->wsize, m->wsize, "FRACTOL");
	m->move_x = 0;
	m->move_y = 0;
	init(m);
	pixel_str(m);
	m->frac = atoi(argv[1]);
	move_xy(m);
	ft_printf("Project %s successfully created! \n", argv[0]);
	ft_putchar('\n');
	set_hooks(m);
	mlx_loop(m->mlx);
	mlx_destroy_image(m->mlx, m->img_ptr);
	sleep(3);
	return (argc);
}
