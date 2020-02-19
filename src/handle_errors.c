/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:37:04 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 13:36:59 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int check_ants_num(char *lines)
{
	int num_limit;
	long long		temp_val;

	num_limit = lines[0] == '-' ? NUM_LEN_WITH_SIGN : NUM_LEN_NO_SIGN;

	if (ft_str_is_numeric_no_spaces(lines) && ft_strlen(lines) <= (size_t)num_limit)
	{
		temp_val = ft_atol(lines);
		if (temp_val > MAX_INTEGER || temp_val < MIN_INTEGER)
			return (0);
	} else
		return (0);
	return (1);
}

int handle_errors(t_lem *lem)
{
	if (lem->ants < 0)
	{
		ft_printf(RED"ERROR: There is no ants or ants are negative\n"RESET);
		exit(free_data(&lem));
	}
	if (lem->end == NULL || lem->start == NULL)
		exit(free_data(&lem));
	if (lem->rooms_cap == 0)
		exit(free_data(&lem));
	return (0);
}