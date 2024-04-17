/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:01:54 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 12:59:08 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_valid_arguments_julia(char **argv)
{
	double	x;
	double	y;

	if (!is_valid_decimal(argv[2]) || !is_valid_decimal(argv[3]))
		return (0);
	x = ft_atod(argv[2]);
	y = ft_atod(argv[3]);
	if (x < -2.0 || x > 2.0 || y < -2 || y > 2)
		return (0);
	else
		return (1);
}

void	usage_message(void)
{
	ft_putstr_fd_nl(STDERR_FILENO, "Usage: ./fractol <type>");
	ft_putstr_fd_nl(STDERR_FILENO, "Available types: mandelbrot, julia");
	exit(EXIT_FAILURE);
}

void	usage_julia_message(void)
{
	ft_putstr_fd(STDERR_FILENO, "Usage: ./fractol julia ");
	ft_putstr_fd_nl(STDERR_FILENO, "<[-2, 2]> <[-2, 2]>");
	exit(EXIT_FAILURE);
}

void	check_arguments(int argc, char **argv, t_fractol **fractol)
{
	if (argc >= 2)
	{
		if (argc == 2 && ft_strcmp(argv[1], FRACTAL_MANDELBROT) == 0)
			return ;
		if (ft_strcmp(argv[1], FRACTAL_JULIA) == 0)
		{
			if (argc != 4 || !is_valid_arguments_julia(argv))
				return (usage_julia_message());
			return ;
		}
	}
	return (usage_message());
}
