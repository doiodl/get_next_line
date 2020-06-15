/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:58:20 by btheia            #+#    #+#             */
/*   Updated: 2019/09/13 16:53:30 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack,
	const char *needle, size_t len)
{
	size_t		len_little;
	size_t		i;

	len_little = ft_strlen(needle);
	if (!ft_strcmp(needle, "\0"))
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0' && len - len_little <= len
		&& i <= len - len_little)
	{
		if (haystack[i] == needle[0])
			if (!ft_strncmp(haystack + i, needle, len_little))
				return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
