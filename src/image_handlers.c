/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:27:08 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/17 12:54:18 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Put image to window and after that destroy the image created.
 */
void	put_image_to_window(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->image->img, 0, 0);
	mlx_destroy_image(fractol->mlx, fractol->image->img);
	free(fractol->image);
}

/**
 * Put pixel color to the image passing its coordinates x and y.
 */
void	put_pixel_to_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * Initialize image and save it inside fractol struct.
 * Set data address.
 * If an error occurred, print error description in standard output and
 * exit with EXIT_FAILURE.
 */
void	init_image(t_fractol *fractol)
{
	fractol->image = malloc(sizeof(t_image));
	if (!fractol->image)
		return (print_error());
	fractol->image->img = mlx_new_image(fractol->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!fractol->image->img)
		return (print_error());
	fractol->image->addr = mlx_get_data_addr(fractol->image->img,
			&fractol->image->bits_per_pixel, &fractol->image->line_length,
			&fractol->image->endian);
	if (!fractol->image->addr)
		return (print_error());
}
