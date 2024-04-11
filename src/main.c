/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:40:04 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/11 02:17:05 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <string.h>
#include <stdio.h>

int	is_valid_arguments_julia(char **argv)
{
	double  x;
  double  y;

	x = ft_atod(argv[2]);
  y = ft_atod(argv[3]);
	if (x < -2.0 || x > 2.0 || y < -1.5 || y > 1.5)
		return (0);
	else
		return (1);
}

void	check_arguments(int argc, char **argv, t_fractol  **fractol)
{
	if (argc >= 2)
	{
		if (argc == 2 && !ft_strcmp(argv[1], FRACTAL_MANDELBROT))
			(*fractol)->type = FRACTAL_MANDELBROT;
	}
  else
  {
    ft_putstr_fd_nl(STDERR_FILENO, "Usage: ./fractol <type>");
    ft_putstr_fd_nl(STDERR_FILENO, "Available types: mandelbrot, julia");
    exit(EXIT_FAILURE);
  }
}

// void	check_arguments(int argc, char **argv, t_fractol  **fractol)
// {
// 	if (argc == 2 && !ft_strcmp(argv[1], FRACTAL_MANDELBROT))
//     (*fractol)->type = FRACTAL_MANDELBROT;
//   else if (argc == 4 && !ft_strcmp(argv[1], FRACTAL_JULIA))
//   {
//     if (!is_valid_arguments_julia(argv))
//     {
//       ft_putstr_fd_nl(STDERR_FILENO,
//         "Usage: ./fractol julia <[-2, 2]> <[-1.5, 1.5]>");
//       exit(EXIT_FAILURE);
//     }
// 		(*fractol)->type = FRACTAL_JULIA;
//   }
//   else
//   {
//     ft_putstr_fd_nl(STDERR_FILENO, "Usage: ./fractol <type>");
//     ft_putstr_fd_nl(STDERR_FILENO, "Available types: mandelbrot, julia");
//     exit(EXIT_FAILURE);
//   }
// }

int	main(int argc, char **argv)
{
  t_fractol *fractol;
  
  fractol = malloc(sizeof(t_fractol));
  
	check_arguments(argc, argv, &fractol);
	return (1);
}

// typedef struct  s_complex
// {
// 	// x = real
// 	double	x;

// 	// i = imaginary
// 	double	i;
// }								t_complex;

// #include <stdio.h>
// int main(void)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	double tmp_real;

// 	z.x = 0;
// 	z.i = 0;

// 	c.x = 0.25;
// 	c.i = 0.4;


// 	for (int i = 0; i < 42; i++)
// 	{
// 		// general formula:
// 		// z = z^2 + c

// 		tmp_real = (z.x * z.x) - (z.i * z.i);
// 		z.i = 2 * z.x * z.i;
// 		z.x = tmp_real;

// 		// adding the c value
// 		z.x += c.x;
// 		z.i += c.i;

// 		printf("iteration %i -> x = %f and y = %f\n", i, z.x, z.i);
// 	}
// 	return 1;
// }

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 9000, 9000);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//   int start_x = 50;
//   int start_y = 50;
//   int size = 500;
//   int i = 0;
//   while (i < size)
//   {
//     my_mlx_pixel_put(&img, start_x + i, start_y, 0x00FF0000 + i);
//     my_mlx_pixel_put(&img, start_x, start_y + i, 0x00FF0000 - i);
//     my_mlx_pixel_put(&img, start_x + size, start_y + i, 0x00FF0000);
//     my_mlx_pixel_put(&img, start_x + i, start_y + size, 0x00FF0000);
//     i++;
//   }
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }