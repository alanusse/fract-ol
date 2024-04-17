/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:25:31 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 11:42:18 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Calculates the number of iterations for a given point (x0, y0) in the
 * Mandelbrot set before the sequence escapes to infinity.
 *
 * @param x0 The real part of the complex number.
 * @param y0 The imaginary part of the complex number.
 * @return The number of iterations before the sequence escapes.
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
 * Draws the Mandelbrot set by iterating over each pixel in the display
 * window, computing the Mandelbrot iteration count for each, and coloring
 * the pixel based on that count.
 *
 * @param fractol A structure containing all the fractal data and settings.
 */
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
