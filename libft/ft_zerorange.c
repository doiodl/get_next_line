/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerorange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:12:32 by btheia            #+#    #+#             */
/*   Updated: 2019/09/18 18:16:16 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_zerorange(size_t len)
{
	size_t	i;
	int		*a;

	if (len == 0)
		return (NULL);
	if (!(a = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
