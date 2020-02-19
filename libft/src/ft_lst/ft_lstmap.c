/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:32:41 by sapril            #+#    #+#             */
/*   Updated: 2019/10/23 13:21:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

static void		free_content(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
	content = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *prev;
	t_list *new_elem;

	head = NULL;
	prev = NULL;
	if (f && lst)
	{
		while (lst)
		{
			if (!(new_elem = f(lst)))
			{
				if (head)
					ft_lstdel(&head, &free_content);
				return (NULL);
			}
			if (prev)
				prev->next = new_elem;
			else
				head = new_elem;
			lst = lst->next;
			prev = new_elem;
		}
	}
	return (head);
}
