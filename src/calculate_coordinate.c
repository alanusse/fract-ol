/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:58:52 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 12:59:29 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_plane	calculate_coordinate(t_fractol *fractol, double px, double py)
{
	t_plane	plane;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	plane.range_x = 4 / fractol->zoom;
	plane.range_y = plane.range_x / aspect_ratio;
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
