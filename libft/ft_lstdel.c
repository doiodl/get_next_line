/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:10:47 by btheia            #+#    #+#             */
/*   Updated: 2019/09/11 19:01:18 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	if (alst == NULL || del == NULL)
		return ;
	node = *alst;
	while (node)
	{
		next = node->next;
		del(node->content, node->content_size);
		free(node);
		node = next;
	}
	*alst = NULL;
}
