/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:21:53 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/14 01:16:30 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_fract *v)
{
	v->min_im -= .1;
	v->max_im -= .1;
}

void	move_down(t_fract *v)
{
	v->min_im += .1;
	v->max_im += .1;
}

void	move_left(t_fract *v)
{
	v->min_re += .1;
	v->max_re += .1;
}

void	move_right(t_fract *v)
{
	v->min_re -= .1;
	v->max_re -= .1;
}
