/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:21:37 by btheia            #+#    #+#             */
/*   Updated: 2019/09/13 16:58:59 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char *sep)
{
	size_t		i;
	size_t		count;
	char		*c;

	if (s[0] == '\0')
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0' && i < ft_strlen(s))
	{
		if (ft_strncmp(&(s[i]), sep, ft_strlen(sep)) != 0)
		{
			count++;
			c = ft_strstr(&(s[i]), sep);
			if (c == NULL)
				return (count);
			i = i + (c - (s + i));
		}
		else
			i = i + ft_strlen(sep);
	}
	return (count);
}

static size_t	word_len(const char *s, char *sep)
{
	char	*c;

	c = ft_strstr(s, sep);
	if (c == NULL)
		return (ft_strlen(s));
	return (c - s);
}

static char		**deltab(char **tab, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

char			**ft_strsplitw(char const *s, char *sep)
{
	char		**tab;
	size_t		word_number;
	size_t		i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	word_number = word_count(s, sep);
	if (!(tab = (char **)malloc(sizeof(char *) * (word_number + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_number)
	{
		while (!ft_strncmp(&s[j], sep, ft_strlen(sep)))
			j = j + ft_strlen(sep);
		tab[i] = ft_strsub(s, j, word_len(s + j, sep));
		if (tab[i] == NULL)
			return (deltab(tab, i));
		j = j + word_len(s + j, sep);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
