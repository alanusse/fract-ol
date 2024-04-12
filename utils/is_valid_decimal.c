/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:44:16 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/13 00:20:21 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_valid_decimal(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str != '.' && *str != '\0')
		return (0);
	if (*str == '\0')
		return (1);
	str++;
	if (*str == '\0')
		return (0);
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}
