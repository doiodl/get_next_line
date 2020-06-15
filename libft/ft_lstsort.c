/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:56:49 by btheia            #+#    #+#             */
/*   Updated: 2019/08/14 18:10:51 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list		*p;
	void		*tmp;
	size_t		stmp;

	p = *begin_list;
	if (!(p))
		return ;
	while (p->next)
	{
		tmp = p->content;
		stmp = p->content_size;
		if ((*cmp)(tmp, p->next->content) > 0)
		{
			p->content = p->next->content;
			p->content_size = p->next->content_size;
			p->next->content_size = stmp;
			p->next->content = tmp;
			p = *begin_list;
			continue;
		}
		p = p->next;
	}
}
