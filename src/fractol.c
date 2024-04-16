/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:15:42 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/16 11:42:17 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void  change_color(t_fractol **fractol)
{
  if ((*fractol)->color >= 2 || (*fractol)->color < 0)
    (*fractol)->color = 0;
  else
    (*fractol)->color += 1;
  draw_fractal(*fractol);
}

void draw_fractal(t_fractol *fractol)
{
  if (ft_strcmp(fractol->name, FRACTAL_MANDELBROT) == 0)
    return (draw_mandelbrot(fractol));
  // todo: draw julia
}

/**
 * Clear and destroy mlx instance and window.
*/
void  destroy_fractol(t_fractol **fractol)
{
  mlx_destroy_window((*fractol)->mlx, (*fractol)->win);
  free(*fractol);
  exit(EXIT_SUCCESS);
}

void  init_fractol(t_fractol **f, char *name)
{
  (*f)->mlx = mlx_init();
  if (!(*f)->mlx)
    return (print_error());
  (*f)->win = mlx_new_window((*f)->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
  if (!(*f)->win)
    return (print_error());
  (*f)->name = name;
  (*f)->zoom = 1.0;
  if (ft_strcmp(name, FRACTAL_MANDELBROT) == 0)
    (*f)->middle_x = -0.75;
  else
    (*f)->middle_x = 0.0;
  (*f)->middle_y = 0.0;
  (*f)->color = 0;
}