/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:24:22 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/03 09:24:23 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>
#include <math.h>

int     keyboard(int keycode, t_frac *s)
{
    if (keycode == 53)
    {
        mlx_destroy_image(s->mlx, s->image.img);
		mlx_destroy_window(s->mlx, s->win);
        exit(0);
    }
	if (keycode >= 123 && keycode <= 126)
	{
		mlx_clear_window(s->mlx, s->win);
		if (keycode == 123)
			s->moveX += 0.3;
		if (keycode == 126)
			s->moveY += 0.3;
		if (keycode == 124)
			s->moveX -= 0.3;
		if (keycode == 125)
            s->moveY -= 0.3;
        printf("%d\n", keycode);
        mlx_destroy_image(s->mlx, s->image.img);
        expose(s);
	}    
    return (0);
}

void    ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

int     mouse_hook(int x, int y, t_frac *s)
{
    if (x >= 0 && x < WIDTH && y >=0 && y <= HEIGHT)
    {
        s->cen.real = (((MAX - MIN) / ((double)(WIDTH) - 0.0)) * ((double)(x) - 0.0)) + MIN;
		s->cen.imag = (((MAX - MIN) / ((double)(HEIGHT) - 0.0)) * ((double)(y) - 0.0)) + MIN;
        mlx_destroy_image(s->mlx, s->image.img);
        mlx_clear_window(s->mlx, s->win);
        expose(s);
    }
    return (0);
}

int     mouse_zoom(int key, int x, int y, t_frac *s)
{
    (void)x;
    (void)y;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
        if (key == 5 || key == 2)
            s->zoom += (s->zoom * 0.30);
        else if (key == 4 || key == 1)
            s->zoom -= (s->zoom * 0.30);
        mlx_destroy_image(s->mlx, s->image.img);
        mlx_clear_window(s->mlx, s->win);
        expose(s);
    }
    return (0);
}