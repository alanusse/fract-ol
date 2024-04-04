/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:12:48 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/04 12:55:06 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sig;

	sig = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = sig * -1;
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sig);
}

static int	check_max(char *s, int flag)
{
	if (flag == 1)
	{
		if (ft_atod(s) < -2.0 || ft_atod(s) > 2.0 \
		|| ft_atoi(s) < -2 || ft_atoi(s) > 2)
			return (1);
	}
	else if (flag == 2)
	{
		if (ft_atod(s) < -1.50 || ft_atod(s) > 1.50)
			return (1);
	}
	return (0);
}

/**
 * Looks if Julia fractol has the correct parameters.
*/
int	look_error(char *argv, int flag)
{
	char	*regex;
	int		i;

	i = 0;
	if (!*argv)
		return (ft_error_print(3));
	else if (check_max(argv, flag) == 1)
		return (ft_error_print(2));
	regex = "-.0123456789";
	while (*argv)
	{
		i = 0;
		while (regex[i] != '\0')
		{
			if (regex[i] == *argv)
				break ;
			i++;
		}
		if (regex[i] == '\0' && regex[i - 1] != *argv)
			return (ft_error_print(3));
		argv++;
	}
	return (0);
}