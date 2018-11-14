/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:25:43 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/13 19:03:06 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** creates a string with alocated space for all pixels on screen
*/

void	pixel_str(t_mlx *m)
{
	m->img_ptr = mlx_new_image(m->mlx, m->width, m->height);
	m->img_int = (int*)mlx_get_data_addr(
		m->img_ptr, &m->bpp, &m->size_line, &m->endian);
}

/*
** puts all pixles to screen, and then destroys the image
*/

void	create_image(t_mlx *m)
{
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
	// mlx_destroy_image(m->mlx, m->img_ptr);///maybe
	// mlx_clear_window(m->mlx, m->win);//////better?
}


//////////////////

void move_xy(t_mlx *m){
	draw_frac(m);
}





void init(t_mlx *m){
	m->height = 1000;
	m->width = 1000;
	m->minRe = -2.0;
	m->maxRe = 2.0;
	m->minIm = -2;
	m->maxIm = 2.0;
	m->maxIterations = 30;
	m->zoom = 1;
	m->re_factor = (m->maxRe - m->minRe) / (m->width);
	m->im_factor = (m->maxIm - m->minIm) / (m->height);
	//
	m->minRe += (((m->width/2) - (m->width/2))  * m->re_factor);// / v->zoom;
	m->maxRe += (((m->width/2) - (m->width/2)) * m->re_factor);// / v->zoom;
	m->minIm -= (((m->height/2) - (m->height/2))  * m->im_factor);// / v->zoom;
	m->maxIm -= (((m->height/2) - (m->height/2)) * m->im_factor);// / v->zoom;
	//
	m->space = 0;
	m->mouse_x = m->width/2;
	m->mouse_y = m->height/2;

	m->color = 1;
	m->color_shift = 0;
}



int		main(int argc, char *argv[])
{
	t_mlx	m;

	ft_bzero(&m, sizeof(m));
	m.wsize = 1000;
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, m.wsize, m.wsize, "FRACTOL");

	m.move_x = 0;//.1;
	m.move_y = 0;//.1;
	init(&m);
	pixel_str(&m);//new


	m.frac = atoi(argv[1]);
	move_xy(&m);
	// draw_frac(&m, m.frac);
	// mlx_clear_window(&m.mlx, &m.win);

	////////////////////////////
	// pixel_str(&m);//new
	// for (int j = 0; j < 3;j++){
	// 	for (int i = j*2; i < (j*2)+10000;i++)
	// 		m.img_int[i] = 0x990000;
	// 	create_image(&m);//new
	// }
	////////////////////////////

	ft_printf("Project %s successfully created! \n", argv[0]);
	ft_putchar('\n');

	set_hooks(&m);
	// mlx_hook(m.win, 2, 0, my_key_funct, &m);

	// mlx_do_sync(m.mlx);
	mlx_loop(m.mlx);

	//Added after
	mlx_destroy_image(m.mlx, m.img_ptr);
	sleep(3);
	return (argc);
}
