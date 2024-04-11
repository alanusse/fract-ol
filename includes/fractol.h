/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:45:12 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/11 12:16:55 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include "../lib/mlx/mlx.h"

/**
 * Fractal names
*/
# define FRACTAL_MANDELBROT "mandelbrot"
# define FRACTAL_JULIA "julia"

/**
 * Fractol settings
 * type: fractal type (mandelbrot, julia)
*/
typedef struct  s_fractol
{
	char	*type;
}               t_fractol;

int     ft_isdigit(char c);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
double	ft_atod(char *str);
void		ft_putstr_fd(int fd, char *str);
void		ft_putstr_fd_nl(int fd, char *str);
void    check_arguments(int argc, char **argv, t_fractol **fractol);

#endif