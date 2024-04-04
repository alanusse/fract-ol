/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:04:21 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/04 12:46:10 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/**
 * Print error
 * Type 1 - Invalid fractal type input.
 * Type 2 - Invalid numbers for Julia fractal.
 * Type 3 - Only prints an error.
*/
int	ft_error_print(int type)
{
	if (type == 1)
	{
		write(1, "Error!\nFractal Options:", 24);
		write(1, "\n./fractol mandelbrot", 22);
		write(1, "\n./fractol julia <[-2, 2]> <[-1.5, 1.5]>", 41);
		write(1, "\n./fractol tricorn\n", 20);
	}
	else if (type == 2)
	{
		write(1, "Error! Number exceeds the Julia supported numbers\n", 51);
		write(1, "./fractol julia <[-2, 2]> <[-1.5, 1.5]>\n", 41);
	}
	else if (type == 3)
	{
		write(1, "Error!\n", 8);
	}
	return (1);
}
