/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:59:01 by btheia            #+#    #+#             */
/*   Updated: 2019/08/12 19:59:04 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_wordtab(char **tab, int key)
{
	char	*tmp;
	char	**a;

	a = tab;
	while (*(tab + 1) != 0)
	{
		tmp = *tab;
		if (ft_strcmp(tmp, *(tab + 1)) * key > 0)
		{
			*tab = *(tab + 1);
			*(tab + 1) = tmp;
			tab = a;
			continue;
		}
		tab++;
	}
	tab = a;
}
