/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:58:19 by btheia            #+#    #+#             */
/*   Updated: 2019/09/04 20:58:21 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*src;

	i = 0;
	ptr = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr[i] != src[i])
			return (ptr[i] - src[i]);
		i++;
	}
	return (0);
}
