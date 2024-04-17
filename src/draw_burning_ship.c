/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:30:09 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/18 00:53:28 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	burning_ship_iterations(double x0, double y0)
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
		y = fabs(2 * x * y) + y0;
		x = fabs(xtemp);
		iter++;
	}
	return (iter);
}

void	draw_burning_ship(t_fractol *fractol)
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
			iterations = burning_ship_iterations(plane.pos_x, plane.pos_y);
			hex_color = get_color(iterations, fractol->color);
			put_pixel_to_img(fractol->image, px, py, hex_color);
		}
	}
	put_image_to_window(fractol);
}
