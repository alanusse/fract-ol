/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:25:31 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/15 01:24:24 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int rgbToHex(int r, int g, int b)
{
    return (r << 16) + (g << 8) + b;
}

unsigned int getColor(int iter)
{
    int r, g, b;
    if (iter == MAX_ITERATIONS) {
        // El punto está dentro del conjunto de Mandelbrot
        r = 0; g = 0; b = 0;
    } else {
        // Generar un gradiente de color suave
        double t = (double)iter / MAX_ITERATIONS;
        r = (int)(9 * (1 - t) * t * t * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
    return rgbToHex(r, g, b);
}

int mandelbrotIterations(double x0, double y0) {
    double x = 0, y = 0;
    double xtemp;
    int iter = 0;
    while (x*x + y*y <= 4 && iter < MAX_ITERATIONS) {
        xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
        iter++;
    }
    return iter;
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  draw_mandelbrot(t_fractol *fractol)
{
  int x;
  int y;
  double x0;
  double y0;

  double zoomFactor = 30.0;
  double centerX = -0.75;
  double centerY = 0.0;

  double rangeX = (1 + 2.5) / zoomFactor; // El rango original es 3.5, dividido por el factor de zoom
  double rangeY = (1.5 + 1.5) / zoomFactor; // El rango original es 3, dividido por el factor de zoom

  double minX = centerX - rangeX / 2;
  double maxX = centerX + rangeX / 2;
  double minY = centerY - rangeY / 2;
  double maxY = centerY + rangeY / 2;

  fractol->image = malloc(sizeof(t_image));
  if(!fractol->image)
    return (print_error());
  fractol->image->img = mlx_new_image(fractol->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
  if(!fractol->image->img)
    return (print_error());
  fractol->image->addr = mlx_get_data_addr(fractol->image->img, &fractol->image->bits_per_pixel, &fractol->image->line_length, &fractol->image->endian);

  y = -1;
  while (++y < WINDOW_HEIGHT)
  {
    x = -1;
    while (++x < WINDOW_WIDTH)
    {
      double x0 = ((double)x / WINDOW_WIDTH) * (maxX - minX) + minX;
      double y0 = ((double)y / WINDOW_HEIGHT) * (maxY - minY) + minY;
      int iter = mandelbrotIterations(x0, y0);
      unsigned int hexColor = getColor(iter);
      put_pixel_to_img(fractol->image, x, y, hexColor);
    }
  }
  mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image->img, 0, 0);
  mlx_destroy_image(fractol->mlx, fractol->image->img);
  free(fractol->image);
}
