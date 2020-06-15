/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:27:39 by btheia            #+#    #+#             */
/*   Updated: 2019/09/14 20:44:04 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int a;
	long int raz;

	raz = 1000000000;
	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = a * (-1);
	}
	while (raz > 1 && !(a / raz))
		raz /= 10;
	while (raz != 0)
	{
		ft_putchar_fd(a / raz + '0', fd);
		a = a % raz;
		raz /= 10;
	}
}
