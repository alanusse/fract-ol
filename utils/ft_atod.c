/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:49:27 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/09 12:56:07 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	ft_decim(char *str, double nb)
{
	double	i;

	i = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		nb += (*str - '0') / i;
		i *= 10.0;
		str++;
	}
	if (*str)
		return (0);
	return (nb);
}

double	ft_atod(char *str)
{
	double	result;
	double	sign;

	sign = 1;
	result = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		result = ft_decim(str, result);
	}
	return (result * sign);
}
