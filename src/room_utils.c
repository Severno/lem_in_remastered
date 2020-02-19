/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:26:32 by sapril            #+#    #+#             */
/*   Updated: 2020/02/11 09:22:19 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int get_real_out_links(t_room *curr_room)
{
	int i;
	int real_out_links;

	i = 0;
	real_out_links = 0;
	if (!curr_room)
		return (0);
	while (i < MIN_LINKS)
	{
		if (curr_room->out_link[i] != NULL && curr_room->out_link[i][0] != '\0')
			real_out_links++;
		i++;
	}
	return (real_out_links);
}

int get_real_in_links(t_room *curr_room)
{
	int i;
	int real_in_links;

	i = 0;
	real_in_links = 0;
	while (i < MIN_LINKS)
	{
		if (curr_room->in_link[i] != NULL && curr_room->in_link[i][0] != '\0')
			real_in_links++;
		i++;
	}
	return (real_in_links);
}