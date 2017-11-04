/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:54:10 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/03 15:33:14 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot(t_frac *s)
{
	s->pos.real = 1.5 * (s->x - WIDTH / 1.8) / (0.5 * s->zoom * WIDTH) + s->moveX;
	s->pos.imag = (s->y - HEIGHT / 2) / (0.5 * s->zoom * HEIGHT) + s->moveY;
	init_vals(s);
	int i = -1;
	while (i++ < s->maxIterations)
	{
		s->old.real = s->neww.real;
		s->old.imag = s->neww.imag;
		s->neww.real = s->old.real * s->old.real - s->old.imag * s->old.imag + s->pos.real;
		s->neww.imag = 2 * s->old.real * s->old.imag + s->pos.imag;
		if((s->neww.real * s->neww.real + s->neww.imag * s->neww.imag) > 4) break;
		set_colours(s, i * 120, 125 * i * i / 3, 225 * (i < s->maxIterations));
		pixel(s, s->x, s->y);
	}
}

void	ft_julia(t_frac *s)
{
	s->neww.real = 1.5 * (s->x - WIDTH / 3) / (0.5 * s->zoom * WIDTH) + s->moveX;
	s->neww.imag = (s->y - HEIGHT / 2) / (0.5 * s->zoom * HEIGHT) + s->moveY;
	int i = -1;
	while (i++ < s->maxIterations && (s->neww.real * s->neww.real + s->neww.imag * s->neww.imag) < 4)
	{
		s->old.real = s->neww.real;
		s->old.imag = s->neww.imag;
		s->neww.real = s->old.real * s->old.real - s->old.imag * s->old.imag + s->cen.real;
		s->neww.imag = 2 * s->old.real * s->old.imag + s->cen.imag;
		set_colours(s, i * 120, 125 * i * i / 3, 225 * (i < s->maxIterations));
		pixel(s, s->x, s->y);
	}
}