/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:01:54 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/11 12:39:46 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_valid_decimal(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str != '.' && *str != '\0')
		return (0);
	if (*str == '\0')
		return (1);
	str++;
	if (*str == '\0')
		return (0);
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}

static int	is_valid_arguments_julia(char **argv)
{
	double	x;
	double	y;

	if (!is_valid_decimal(argv[2]) || !is_valid_decimal(argv[3]))
		return (0);
	x = ft_atod(argv[2]);
	y = ft_atod(argv[3]);
	if (x < -2.0 || x > 2.0 || y < -1.5 || y > 1.5)
		return (0);
	else
		return (1);
}

/**
 * Check if arguments are valid and set fractol->type, if there
 * is an error, print error message and exit with EXIT_FAILURE code.
 */
void	check_arguments(int argc, char **argv, t_fractol **fractol)
{
	if (argc == 2 && ft_strcmp(argv[1], FRACTAL_MANDELBROT) == 0)
	{
		(*fractol)->type = FRACTAL_MANDELBROT;
		return ;
	}
	if (argc >= 2 && ft_strcmp(argv[1], FRACTAL_JULIA) == 0)
	{
		if (argc != 4 || !is_valid_arguments_julia(argv))
		{
			ft_putstr_fd(STDERR_FILENO, "Usage: ./fractol julia ");
			ft_putstr_fd_nl(STDERR_FILENO, "<[-2, 2]> <[-1.5, 1.5]>");
			exit(EXIT_FAILURE);
		}
		(*fractol)->type = FRACTAL_JULIA;
		return ;
	}
	ft_putstr_fd_nl(STDERR_FILENO, "Usage: ./fractol <type>");
	ft_putstr_fd_nl(STDERR_FILENO, "Available types: mandelbrot, julia");
	exit(EXIT_FAILURE);
}
