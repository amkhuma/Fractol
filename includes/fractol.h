/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:24:35 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/03 09:24:36 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include    <mlx.h>
#include <stdlib.h>
#include "../libft/libft.h"

# define HEIGHT 500
# define WIDTH 500

# define MIN -3.20
# define MAX 3.200

typedef struct  s_rgb
{
    int r;
    int g;
    int b;
}               t_rgb;

typedef struct	s_img
{
    void *img;
    char *d;
    int bpp;
    int s;
    int e;
}                t_img;

typedef struct  s_values
{
    double      real;
    double      imag;
}               t_values;

typedef struct  s_frac
{
    int         x;
    int         y;
    double      zoom;
    double      moveX;
    double      moveY;
    int         maxIterations;
    t_rgb       color;
    t_img       image;
    t_values    cen;
    t_values    pos;
    t_values    neww;
    t_values    old;
    char        *fractal;
    void        *mlx;
    void        *win;
}               t_frac;

void    screen_loop(t_frac *s);
void    ft_error(char *s);
int     init(t_frac *s);
int     key_exit(int keycode, t_frac *s);
int     keyboard(int keycode, t_frac *s);
int     init_mandelbrot(t_frac *s);
int     init_vals(t_frac *s);
void    ft_mandelbrot(t_frac *s);
void    ft_julia(t_frac *s);
int     init_julia(t_frac *s);
void    pixel(t_frac *s, int x, int y);
void    set_colours(t_frac *s, int r, int g, int b);
int     expose(t_frac *s);
int     mouse_zoom(int key, int x, int y, t_frac *s);
int     mouse_hook(int x, int y, t_frac *s);

#endif