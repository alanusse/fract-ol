/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:01:41 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 13:03:40 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	get_color(int iterations, int palette)
{
	double	t;

	if (iterations == MAX_ITERATIONS)
		return (rgb_to_hex(0, 0, 0));
	t = (double)iterations / MAX_ITERATIONS;
	if (palette == 1)
		return (rgb_to_hex((int)(255 * (0.5 * sin(6 * 3.14159 * t) + 0.5)),
			(int)(255 * (0.5 * sin(6 * 3.14159 * t + 2.09439) + 0.5)),
			(int)(255 * (0.5 * sin(6 * 3.14159 * t + 4.18879) + 0.5))));
	else if (palette == 2)
		return (rgb_to_hex((int)(255 * (0.5 * cos(12 * 3.14159 * t) + 0.5)),
			(int)(255 * (0.5 * sin(24 * 3.14159 * t) + 0.5)),
			(int)(255 * (0.5 * cos(18 * 3.14159 * t + 3.14159) + 0.5))));
	else
		return (rgb_to_hex((int)(9 * (1 - t) * t * t * t * 255),
			(int)(15 * (1 - t) * (1 - t) * t * t * 255),
			(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)));
}
