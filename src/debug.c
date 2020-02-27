/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:59:21 by sapril            #+#    #+#             */
/*   Updated: 2020/02/27 16:59:21 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*get_color(int i_path)
{
	int	tmp;

	tmp = i_path + 1;
	while (tmp - NB_PATHS_COLORS > 0)
		tmp -= NB_PATHS_COLORS;
	if (tmp == 1)
		return (GREEN);
	if (tmp == 2)
		return (YELLOW);
	if (tmp == 3)
		return (BLUE);
	if (tmp == 4)
		return (MAGENTA);
	return (NC);
}

void	display_paths(t_engine *engine)
{
	int		i;
	int		j;

	i = 0;
	while (i < engine->nb_paths)
	{
		j = 1;
		if (engine->color)
			ft_putstr(get_color(i));
		ft_putstr("PATH NUMBER ");
		ft_putnbr(i);
		ft_putstr(" has as a dist : ");
		ft_putnbr(engine->paths[i][0]);
		ft_putstr(" and is : ");
		while (j < engine->paths[i][0])
		{
			ft_putstr(engine->rooms[engine->paths[i][j]].name);
			ft_putchar('-');
			j++;
		}
		ft_putstr(engine->rooms[engine->paths[i][j]].name);
		ft_putchar('\n');
		i++;
	}
	ft_putstr(NC"\n");
}
