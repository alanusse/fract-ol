/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:45:12 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 12:51:13 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../lib/mlx/mlx.h"

/**
 * Window settings
 */
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 42
# define ZOOM_FACTOR 0.7
# define MOVEMENT_FACTOR 0.5

/**
 * Keys definitions
*/
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define ON_DESTROY 17
# define ESC_KEY 53
# define ARROW_LEFT_KEY 123
# define ARROW_RIGHT_KEY 124
# define ARROW_DOWN_KEY 125
# define ARROW_UP_KEY 126
# define C_KEY 8

/**
 * Fractal names
 */
# define FRACTAL_MANDELBROT "mandelbrot"
# define FRACTAL_JULIA "julia"

/**
 * Image structure
 */
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}							t_image;

/**
 * Fractol settings
 */
typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_image		*image;
	char		*name;
	double		zoom;
	double		middle_x;
	double		middle_y;
	double		cr_julia;
	double		ci_julia;
	int			color;
}							t_fractol;

typedef struct s_plane
{
	double	pos_x;
	double	pos_y;
	double	range_x;
	double	range_y;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}							t_plane;

void					print_error(void);
int						is_valid_decimal(char *str);
int						ft_isdigit(char c);
int						ft_strlen(char *str);
int						ft_strcmp(char *s1, char *s2);
double					ft_atod(char *str);
void					ft_putstr_fd(int fd, char *str);
void					ft_putstr_fd_nl(int fd, char *str);
void					check_arguments(int argc, char **argv,
							t_fractol **fractol);
void					draw_mandelbrot(t_fractol *fractol);
void					draw_julia(t_fractol *fractol);
void					put_pixel_to_img(t_image *img, int x, int y, int color);
unsigned int			rgb_to_hex(int r, int g, int b);
void					put_image_to_window(t_fractol *fractol);
void					init_image(t_fractol *fractol);
void					draw_fractal(t_fractol *fractol);
void					init_fractol(t_fractol **f, char **argv);
void					init_handlers(t_fractol **fractol);
void					destroy_fractol(t_fractol **fractol);
void					change_color(t_fractol **fractol);
unsigned int			get_color(int iterations, int palette);
t_plane					calculate_coordinate(t_fractol *fractol, double px,
							double py);

#endif