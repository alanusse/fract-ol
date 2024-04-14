/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:40:04 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/15 00:22:20 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void draw_fractal(t_fractol *fractol)
{
  if (ft_strcmp(fractol->name, FRACTAL_MANDELBROT) == 0)
    return (draw_mandelbrot(fractol));
  // todo: draw julia
}

static void init_fractol(t_fractol **f, char *name)
{
  (*f)->mlx = mlx_init();
  if (!(*f)->mlx)
    return (print_error());
  (*f)->win = mlx_new_window((*f)->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
  if (!(*f)->win)
    return (print_error());
  (*f)->name = name;
  (*f)->zoom = 1.0;
  (*f)->zoom_pos_x = WINDOW_WIDTH / 2;
  (*f)->zoom_pos_y = WINDOW_HEIGHT / 2;
}

/**
 * Zoom over fractal and draw fractal again with applied zoom.
*/
int handle_zoom(int code, int x, int y, t_fractol **fractol)
{
  if (code == MOUSE_SCROLL_UP || code == MOUSE_SCROLL_DOWN)
  {
    if (code == MOUSE_SCROLL_DOWN)
      (*fractol)->zoom *= ZOOM_FACTOR;
    if (code == MOUSE_SCROLL_UP)
      (*fractol)->zoom /= ZOOM_FACTOR;
    (*fractol)->zoom_pos_x = x;
    (*fractol)->zoom_pos_y = y;
    draw_fractal(*fractol);
  }
  return (0);
}

int	main(int argc, char **argv)
{
  t_fractol *fractol;
  
  fractol = malloc(sizeof(t_fractol));
  if (!fractol)
    print_error();
	check_arguments(argc, argv, &fractol);
  init_fractol(&fractol, argv[1]);
  draw_fractal(fractol);
  mlx_mouse_hook(fractol->win, handle_zoom, &fractol);
  // mlx_key_hook(fractol->win, key_hook, &fractol);
  mlx_loop(fractol->mlx);
	return (1);
}
