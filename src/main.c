/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:40:04 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/14 13:38:06 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void draw_fractal(char *type, t_fractol *fractol)
{
  if (ft_strcmp(type, FRACTAL_MANDELBROT) == 0)
    return (draw_mandelbrot(fractol));
  // todo: draw julia
}

static void init_fractol(t_fractol **fractol)
{
  t_fractol *f;

  f = *fractol;
  f->mlx = mlx_init();
  if (!f->mlx)
    return (print_error());
  f->win = mlx_new_window(f->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
  if (!f->win)
    return (print_error());
  f->image.img = mlx_new_image(f->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
  if (!f->image.img)
    return (print_error());
  f->image.addr = mlx_get_data_addr(f->image.img, &f->image.bits_per_pixel,
    &f->image.line_length, &f->image.endian);
  f->zoom_factor = 1.0;
}

int	main(int argc, char **argv)
{
  t_fractol *fractol;
  
  fractol = malloc(sizeof(t_fractol));
  if (!fractol)
    print_error();
	check_arguments(argc, argv, &fractol);
  init_fractol(&fractol);
  draw_fractal(argv[1], fractol);
  mlx_loop(fractol->mlx);
	return (1);
}
