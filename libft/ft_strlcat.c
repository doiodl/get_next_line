/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:25:35 by btheia            #+#    #+#             */
/*   Updated: 2019/09/11 14:01:54 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src,
	size_t size)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;
	size_t	j;

	i = 0;
	d_size = ft_strlen(dst);
	s_size = ft_strlen((char*)src);
	i = d_size;
	j = 0;
	if (size == 0)
		return (s_size + size);
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (d_size + s_size < size + s_size)
		return (d_size + s_size);
	return (size + s_size);
}
