/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:52:42 by btheia            #+#    #+#             */
/*   Updated: 2019/09/06 11:53:55 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*tmp;

	if (s == NULL)
		return (NULL);
	tmp = (char*)s;
	if (*s == ' ' || *s == '\t' || *s == '\n')
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		tmp = (char*)s + i;
		if (*tmp == '\0')
			return (ft_strdup(""));
	}
	len = ft_strlen(s) - 1;
	if (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
	{
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		return (ft_strsub(s, i, len - i + 1));
	}
	return (tmp == s) ? ft_strdup((char*)s) : ft_strdup((char*)s + i);
}
