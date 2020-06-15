/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:52:42 by btheia            #+#    #+#             */
/*   Updated: 2019/09/13 16:08:46 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	t_list		*tmp;
	size_t		i;

	i = 1;
	if (begin_list == 0)
		return (0);
	tmp = begin_list;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
