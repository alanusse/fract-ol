/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:51:07 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/04 12:55:28 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static double	ft_decim(char *str, double nb)
{
	double	i;

	i = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb + (*str - '0') / i;
		i *= 10.0;
		str++;
	}
	if (*str)
		return (0);
	return (nb);
}

double	ft_atod(char *str)
{
	double	nb;
	double	sig;

	sig = 1;
	nb = 0;
	if (*str == '-')
	{
		sig = sig * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		nb = ft_decim(str, nb);
	}
	else
		return (0.0);
	return (nb * sig);
}
