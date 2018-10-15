/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:21:53 by hasmith           #+#    #+#             */
/*   Updated: 2018/10/14 19:38:50 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_mlx *v)
{
	v->minIm -= .1;//fabs(v->minIm * 0.1);
	v->maxIm -= .1;//fabs(v->maxIm * 0.1);
}

void	move_down(t_mlx *v)
{
	v->minIm += .1;//fabs(v->minIm * 0.1);
	v->maxIm += .1;//fabs(v->maxIm * 0.1);
}

void	move_left(t_mlx *v)
{
	v->minRe += .1;//fabs(v->minRe * 0.1);
	v->maxRe += .1;//fabs(v->maxRe * 0.1);
}

void	move_right(t_mlx *v)
{
	v->minRe -= .1;//fabs(v->minRe * 0.1);
	v->maxRe -= .1;//fabs(v->maxRe * 0.1);
}