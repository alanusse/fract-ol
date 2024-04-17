/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:30:21 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 12:58:27 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Computes the number of iterations for a given point (x, y) in the Julia set
 * before the sequence escapes the bounded region. The constants cr_julia and
 * ci_julia are part of the fractol structure and define the specific Julia set.
 *
 * @param fractol The fractol structure containing parameters for the Julia set.
 * @param x The real part of the initial complex number.
 * @param y The imaginary part of the initial complex number.
 * @return The number of iterations before the sequence escapes or reaches the
 * maximum iteration limit.
 */
static int	julia_iterations(t_fractol *fractol, double x, double y)
{
	double	xtemp;
	int		iter;

	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITERATIONS)
	{
		xtemp = x * x - y * y + fractol->cr_julia;
		y = 2 * x * y + fractol->ci_julia;
		x = xtemp;
		iter++;
	}
	return (iter);
}

/**
 * Renders the Julia set on the screen by iterating over each pixel, calculating
 * the corresponding complex number, and determining the color based on the
 * number of iterations to escape.
 *
 * @param fractol A structure containing all the fractal data and settings.
 */
void	draw_julia(t_fractol *fractol)
{
	int				px;
	int				py;
	int				iterations;
	unsigned int	hex_color;
	t_plane			plane;

	init_image(fractol);
	py = -1;
	while (++py < WINDOW_HEIGHT)
	{
		px = -1;
		while (++px < WINDOW_WIDTH)
		{
			plane = calculate_coordinate(fractol, px, py);
			iterations = julia_iterations(fractol, plane.pos_x, plane.pos_y);
			hex_color = get_color(iterations, fractol->color);
			put_pixel_to_img(fractol->image, px, py, hex_color);
		}
	}
	put_image_to_window(fractol);
}
