/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:19:31 by btheia            #+#    #+#             */
/*   Updated: 2019/09/13 14:43:03 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_l(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst->content);
		free(lst);
		lst = temp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = f(lst);
	if (new_list == NULL)
		return (NULL);
	node = new_list;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		if (node->next == NULL)
		{
			del_l(new_list);
			return (NULL);
		}
		node = node->next;
	}
	return (new_list);
}
