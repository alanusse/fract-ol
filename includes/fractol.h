/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:45:12 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/15 00:07:53 by aglanuss         ###   ########.fr       */
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
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 50
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define ZOOM_FACTOR 0.7

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
	t_image	*image;
	char		*name;
	double	zoom;
	int			zoom_pos_x;
	int			zoom_pos_y;
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
void		put_pixel_to_img(t_image *img, int x, int y, int color);
unsigned int	rgb_to_hex(int r, int g, int b);

#endif