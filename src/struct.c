/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:14:11 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/24 16:59:43 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_struct(t_fract *f)
{
	f->mlx_ptr = NULL;
	f->win_ptr = NULL;
	f->mlx_image = NULL;
	f->windowheight = DEFAULTHEIGHT;
	f->windowwidth = DEFAULTWIDTH;
	f->center_x = f->windowwidth / 2;
	f->center_y = f->windowheight / 2;
	f->zoom = 1;
	f->type = Mandelbrot;
	f->arg = 0;
	f->iters = 42;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->update = 1;
	f->display_text = 1;
	f->lock = 0;
}

void			*make_thread_arg(t_fract *f, int start_y, int end_y)
{
	t_targ		*ptr;

	if (!(ptr = malloc(sizeof(t_targ))))
		exit(1);
	ptr->f = f;
	ptr->start_y = start_y;
	ptr->end_y = end_y;
	return (ptr);
}

/*
** t_point	point;
** {
**	point.x = 2.0 * (x - window->center->x) / (0.5 * window->zoom * IMG_SIZE);
**	point.y = 2.0 * (y - window->center->y) / (0.5 * window->zoom * IMG_SIZE);
**	return (point);
** }
*/

t_vect3			*scale_point(t_fract *f, int x, int y)
{
	t_vect3		*v;

	if (!(v = ft_memalloc(sizeof(t_vect3))))
		exit(1);
	v->x = 2.0 * (x - f->center_x) / (0.5 * f->zoom * f->windowwidth);
	v->y = 2.0 * (y - f->center_y) / (0.5 * f->zoom * f->windowwidth);
	v->z = 0;
	return (v);
}
