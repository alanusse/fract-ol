/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:25:31 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/16 12:09:37 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Get coordinates from mandelbrot plane and return the number
 * of itertions it takes.
*/
static int	mandelbrot_iterations(double x0, double y0)
{
	double	x;
	double	y;
	double	xtemp;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITERATIONS)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		iter++;
	}
	return (iter);
}

/**
 * Transform coordinates from screen to coordinates from mandelbrot.
*/
static t_plane	calculate_coordinate(t_fractol *fractol, double px, double py)
{
	t_plane	plane;

	plane.range_x = (1 + 2.5) / fractol->zoom;
	plane.range_y = (1.5 + 1.5) / fractol->zoom;
	plane.min_x = fractol->middle_x - plane.range_x / 2;
	plane.max_x = fractol->middle_x + plane.range_x / 2;
	plane.min_y = fractol->middle_y - plane.range_y / 2;
	plane.max_y = fractol->middle_y + plane.range_y / 2;
	plane.pos_x = ((double)px / WINDOW_WIDTH)
		* (plane.max_x - plane.min_x) + plane.min_x;
	plane.pos_y = ((double)py / WINDOW_HEIGHT)
		* (plane.max_y - plane.min_y) + plane.min_y;
	return (plane);
}

void	draw_mandelbrot(t_fractol *fractol)
{
	int						px;
	int						py;
	int						iterations;
	unsigned int			hex_color;
	t_plane					plane;

	init_image(fractol);
	py = -1;
	while (++py < WINDOW_HEIGHT)
	{
		px = -1;
		while (++px < WINDOW_WIDTH)
		{
			plane = calculate_coordinate(fractol, px, py);
			iterations = mandelbrot_iterations(plane.pos_x, plane.pos_y);
			hex_color = get_color(iterations, fractol->color);
			put_pixel_to_img(fractol->image, px, py, hex_color);
		}
	}
	put_image_to_window(fractol);
}
