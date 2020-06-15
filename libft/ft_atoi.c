/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:35:46 by btheia            #+#    #+#             */
/*   Updated: 2019/09/05 12:36:05 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+' && sign == 1)
		str++;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && (n > FT_LONG_MAX || (n == FT_LONG_MAX && *str > '7')))
			return (-1);
		if (sign == -1 && (n > FT_LONG_MAX || (n == FT_LONG_MAX && *str > '8')))
			return (0);
		n = 10 * n + sign * (*str - '0');
		str++;
	}
	return (n);
}
