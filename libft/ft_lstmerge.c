/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:22:14 by btheia            #+#    #+#             */
/*   Updated: 2019/08/14 17:32:17 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list **p;

	p = begin_list1;
	if (!(*p))
	{
		*p = begin_list2;
		return ;
	}
	while ((*p)->next)
	{
		p = &(*p)->next;
	}
	(*p)->next = begin_list2;
}
