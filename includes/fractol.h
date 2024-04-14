/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:45:12 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/14 13:37:07 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/mlx/mlx.h"

/**
 * Window settings
*/
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 1000

/**
 * Fractal names
*/
# define FRACTAL_MANDELBROT "mandelbrot"
# define FRACTAL_JULIA "julia"

/**
 * Image structure
*/
typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}								t_image;

/**
 * Fractol settings
*/
typedef struct  s_fractol
{
	void		*mlx;
	void		*win;
	t_image	image;
	double	zoom_factor;
}               t_fractol;

void		print_error(void);
int			is_valid_decimal(char *str);
int     ft_isdigit(char c);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
double	ft_atod(char *str);
void		ft_putstr_fd(int fd, char *str);
void		ft_putstr_fd_nl(int fd, char *str);
void    check_arguments(int argc, char **argv, t_fractol **fractol);
void		draw_mandelbrot(t_fractol *fractol);

#endif