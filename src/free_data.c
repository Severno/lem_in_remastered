/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:16:29 by sapril            #+#    #+#             */
/*   Updated: 2020/02/05 13:00:03 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int freed_in = 0;
int freed_out = 0;
int freed_rooms = 0;

int				free_data(t_lem **lem)
{
	int i;

	i = 0;
	while (i < TABLE_SIZE)
		free_entries(lem, i++);
	free_lem(lem);
	return (1);
}

void 			free_entries(t_lem **lem, int i)
{
	t_entry	*entry;
	char	**in_links;
	char	**out_links;

	if ((*lem)->ht->entries[i])
	{
		entry = (*lem)->ht->entries[i];
		if (entry->value)
		{
			in_links = entry->value->in_link;
			out_links = entry->value->out_link;
			free_str_links(&in_links, &out_links);
			free_entry(&entry);
//			ft_printf("freed rooms = %d\n", ++freed_rooms);
		}
	}
	free((*lem)->ht->entries[i]);
	(*lem)->ht->entries[i] = NULL;
}

void			free_entry(t_entry **entry)
{
	(*entry)->value->name ? free((*entry)->value->name) : 0;
	(*entry)->value ? free((*entry)->value) : 0;
	(*entry)->key ? free((*entry)->key) : 0;
}

void			free_lem(t_lem **lem)
{

	(*lem)->ht->entries ? free((*lem)->ht->entries) : 0;
	(*lem)->ht ? free((*lem)->ht) : 0;
	(*lem)->names ? free((*lem)->names) : 0;
	(*lem)->end ? free((*lem)->end) : 0;
	(*lem)->start ? free((*lem)->start) : 0;
	(*lem) ? free((*lem)) : 0;
}
