/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:25:43 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/15 16:41:27 by hasmith          ###   ########.fr       */
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

void move_xy(t_mlx *mast){
	draw_frac(mast);
}





void init(t_mlx *mast){
	mast->height = 1000;
	mast->width = 1000;
	mast->minRe = -2.0;
	mast->maxRe = 1.0;
	mast->minIm = -1.2;
	mast->maxIterations = 30;
	mast->zoom = 1;
	mast->maxIm = 2.0;

}

void		set_hooks(t_mlx *m)
{
	// mlx_hook(m->win, 12, 0, expose_hook, m);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	// mlx_hook(m->win, 3, 0, key_release_hook, m);
	// mlx_hook(m->win, 4, 0, mouse_press_hook, m);
	// mlx_hook(m->win, 5, 0, mouse_release_hook, m);

	mlx_hook(m->win, 6, 0, mouse_motion_hook, m);
	
	// mlx_hook(m->win, 17, 0, exit_hook, m);
}

int		main(int argc, char *argv[])
{
	t_mlx	mast;

	ft_bzero(&mast, sizeof(mast));
	mast.wsize = 1000;
	mast.mlx = mlx_init();
	mast.win = mlx_new_window(mast.mlx, mast.wsize, mast.wsize, "FRACTOL");

	mast.move_x = 0;//.1;
	mast.move_y = 0;//.1;
	init(&mast);
	pixel_str(&mast);//new

	mast.frac = atoi(argv[1]);
	// draw_frac(&mast, mast.frac);
	// mlx_clear_window(&mast.mlx, &mast.win);

	////////////////////////////
	// pixel_str(&mast);//new
	// for (int j = 0; j < 3;j++){
	// 	for (int i = j*2; i < (j*2)+10000;i++)
	// 		mast.img_int[i] = 0x990000;
	// 	create_image(&mast);//new
	// }
	////////////////////////////

	ft_printf("Project %s successfully created! \n", argv[0]);
	ft_putchar('\n');

	set_hooks(&mast);
	// mlx_hook(mast.win, 2, 0, my_key_funct, &mast);

	// mlx_do_sync(mast.mlx);
	mlx_loop(mast.mlx);

	//Added after
	// mlx_destroy_image(mast.mlx, mast.img_ptr);
	sleep(3);
	return (argc);
}
