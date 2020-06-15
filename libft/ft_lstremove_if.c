/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:19:11 by btheia            #+#    #+#             */
/*   Updated: 2019/08/14 14:53:01 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list **p;

	p = begin_list;
	while (*p)
	{
		if ((*cmp)((*p)->content, data_ref) == 0)
		{
			tmp = (*p)->next;
			free(*p);
			*p = tmp;
		}
		else
			p = &(*p)->next;
	}
}
