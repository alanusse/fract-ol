/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:25:31 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/15 21:52:17 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int get_color(int iterations)
{
  int r;
  int g;
  int b;
  double t;

  if (iterations == MAX_ITERATIONS)
  {
    r = 0;
    g = 0;
    b = 0;
  }
  else
  {
    t = (double)iterations / MAX_ITERATIONS;
    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
  }
  return rgb_to_hex(r, g, b);
}

int mandelbrot_iterations(double x0, double y0)
{
    double x;
    double y;
    double xtemp;
    int iter;

    x = 0;
    y = 0;
    iter = 0;
    while (x * x + y * y <= 4 && iter < MAX_ITERATIONS) {
      xtemp = x * x - y * y + x0;
      y = 2 * x * y + y0;
      x = xtemp;
      iter++;
    }
    return (iter);
}

void  calculate_coordinate(t_fractol *fractol, double px, double py, double *x0, double *y0)
{
  double rangeX = (1 + 2.5) / fractol->zoom;
  double rangeY = (1.5 + 1.5) / fractol->zoom;

  double minX = fractol->middle_x - rangeX / 2;
  double maxX = fractol->middle_x + rangeX / 2;
  double minY = fractol->middle_y - rangeY / 2;
  double maxY = fractol->middle_y + rangeY / 2;
  *x0 = ((double)px / WINDOW_WIDTH) * (maxX - minX) + minX;
  *y0 = ((double)py / WINDOW_HEIGHT) * (maxY - minY) + minY;
}

void  draw_mandelbrot(t_fractol *fractol)
{
  int px;
  int py;
  double x0;
  double y0;
  int iterations;
  unsigned int hexColor;

  init_image(fractol);
  py = -1;
  while (++py < WINDOW_HEIGHT)
  {
    px = -1;
    while (++px < WINDOW_WIDTH)
    {
      calculate_coordinate(fractol, px, py, &x0, &y0);
      iterations = mandelbrot_iterations(x0, y0);
      hexColor = get_color(iterations);
      put_pixel_to_img(fractol->image, px, py, hexColor);
    }
  }
  put_image_to_window(fractol);
}
