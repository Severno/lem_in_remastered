/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:17:21 by sapril            #+#    #+#             */
/*   Updated: 2020/02/23 18:46:36 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			main(int argc, char *argv[])
{
	t_lem *lem;
	t_room *start;
	(void)argc;
	(void)argv;

	lem = create_lem_in();
	parse(lem);
	start = ht_get(lem->ht, lem->start);
	print_lines(lem->concat->lines);
	bfs_assign_lvl_room(lem, start, lem->end);
	delete_useless_links(lem, start);
	create_in_out_links(lem, start);
//	print_rooms(lem);
	delete_input_links(lem, start);
	delete_output_links(lem, start);
//	delete_out_links(lem, start);
//	print_rooms_out_in(lem);

//	find_shortest_path(lem, start, lem->end);
////	print_rooms(lem);
//	sleep(100);
	lem->valid_paths = form_paths(lem, start);
//	print_paths_linked_list(lem, start);
//	sleep(1000);
	launch_ants(lem,  ht_get(lem->ht, lem->start), lem->ants);
	free_data(&lem);
//	delete_output_links(lem, start);
	return (0);
}