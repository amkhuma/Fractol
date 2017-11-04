/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:09:14 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/03 11:09:28 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int     init_mandelbrot(t_frac *s)
{
    s->zoom = 1;
    s->moveX = 0;
    s->moveY = 0;
    s->maxIterations = 300;
    return (0);
}

int     init_vals(t_frac *s)
{
    s->neww.real = 0;
    s->neww.imag = 0;
    s->old.real = 0;
    s->old.imag = 0;
    return (0);
}

int     init_julia(t_frac *s)
{
    s->zoom = 1;
    s->moveX = -0.5;
    s->moveY = 0;
	s->maxIterations = 300;
	s->cen.real = -0.7;
    s->cen.imag = 0.27015;
    return (0);
}