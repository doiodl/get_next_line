/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:51:18 by btheia            #+#    #+#             */
/*   Updated: 2019/09/05 11:51:31 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmp;
	char *s1;
	char *s2;

	tmp = (char*)haystack;
	if (*needle == 0)
		return ((char*)haystack);
	while (*tmp != '\0')
	{
		s1 = tmp;
		s2 = (char*)needle;
		while (*s1 == *s2 && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (tmp);
		tmp++;
	}
	return (0);
}
