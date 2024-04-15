/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:40:04 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/15 21:49:52 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
  t_fractol *fractol;
  
  fractol = malloc(sizeof(t_fractol));
  if (!fractol)
    print_error();
	check_arguments(argc, argv, &fractol);
  init_fractol(&fractol, argv[1]);
  init_handlers(&fractol);
  draw_fractal(fractol);
  mlx_loop(fractol->mlx);
	return (1);
}
