/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:15:52 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/09 11:33:24 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_putstr_fd(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
		write(fd, str, len);
}

void	ft_putstr_fd_nl(int fd, char *str)
{
  ft_putstr_fd(fd, str);
  write(fd, "\n", 1);
}
