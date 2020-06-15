/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:38:22 by btheia            #+#    #+#             */
/*   Updated: 2019/09/06 12:38:48 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_d(long int num, int sign)
{
	int			raz;

	raz = 1;
	if (sign == -1)
		raz++;
	while (num >= 10)
	{
		raz++;
		num = num / 10;
	}
	return (raz);
}

char		*ft_itoa(int n)
{
	int			raz;
	char		*ptr;
	long int	num;
	int			sign;

	num = n;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		num = num * sign;
	}
	raz = count_d(num, sign);
	ptr = (char*)malloc(sizeof(char) * (raz + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[raz] = '\0';
	while (--raz >= 0)
	{
		ptr[raz] = num % 10 + '0';
		num = num / 10;
	}
	if (sign == -1)
		ptr[0] = '-';
	return (ptr);
}
