/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:25:43 by hasmith           #+#    #+#             */
/*   Updated: 2018/04/05 02:54:50 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_key_funct(int keycode, t_mlx *mast)
{
	(void)mast;
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_mlx	mast;

	ft_bzero(&mast, sizeof(mast));
	mast.wsize = 1000;
	mast.mlx = mlx_init();
	mast.win = mlx_new_window(mast.mlx, mast.wsize, mast.wsize, "FRACTOL");
	// pixel_str(&mast);


	ft_printf("Project %s successfully created! \n", argv[0]);
	ft_putchar('\n');

	mlx_hook(mast.win, 2, 0, my_key_funct, &mast);
	mlx_do_sync(mast.mlx);

	// mlx_destroy_image(mast.mlx, mast.img_ptr);
	sleep(3);
	return (argc);
}
