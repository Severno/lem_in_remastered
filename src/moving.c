#include "../includes/lem_in.h"

static int		print_ant(t_engine *engine, int index, int print_space)
{
	int index_of_room;
	int index_of_path;

	engine->ants[index].cur_pos += 1;
	index_of_path = engine->ants[index].path_chosen;
	index_of_room = engine->paths[index_of_path][engine->ants[index].cur_pos];
	if (engine->color)
		ft_putstr(get_color(index_of_path));
	if (print_space)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(index + 1);
	ft_putchar('-');
	ft_putstr(engine->rooms[index_of_room].name);
	ft_putstr(NC);
	return (1);
}

static int		maybe_print_ant(t_engine *engine, int index, int print_space)
{
	int		index_prev;

	if (engine->ants[index].cur_pos ==
		engine->paths[engine->ants[index].path_chosen][0])
		return (0);
	if (engine->ants[index].cur_pos != 1)
		return (print_ant(engine, index, print_space));
	index_prev = index - engine->nb_paths;
	if (index_prev < 0)
	{
		return (print_ant(engine, index, print_space));
	}
	if (engine->ants[index_prev].cur_pos ==
		engine->paths[engine->ants[index].path_chosen][0])
		return (print_ant(engine, index, print_space));
	if (engine->ants[index_prev].cur_pos != 1 &&
		engine->ants[index_prev].cur_pos != 2)
		return (print_ant(engine, index, print_space));
	return (0);
}

static void		move_ants(t_engine *engine)
{
	int		ant;
	int		print_space;

	while (continue_moving(engine))
	{
		ant = 0;
		print_space = 0;
		while (ant < engine->nbr_ants)
		{
			print_space += maybe_print_ant(engine, ant, print_space);
			print_space = print_space > 1 ? print_space - 1 : print_space;
			ant++;
		}
		ft_putchar('\n');
	}
}

/*
** Index_lower is the number of the ant if there was only x ant,
** x being the number of paths.
*/

static t_ant	create_ant(int nb_paths, int ant_nb)
{
	t_ant	new_ant;
	int		i_path;
	int		best_path_found;
	int		index_lower;

	index_lower = get_index_lower(nb_paths, ant_nb);
	i_path = nb_paths;
	new_ant.cur_pos = 1;
	best_path_found = 0;
	while (i_path != 0 && best_path_found == 0)
	{
		if (index_lower % i_path == 0)
		{
			new_ant.path_chosen = i_path - 1;
			best_path_found = 1;
		}
		i_path--;
	}
	if (best_path_found == 0)
		new_ant.path_chosen = 0;
	return (new_ant);
}

void			init_ants(t_engine *engine)
{
	int		i;

	engine->ants = (t_ant *)ft_memalloc(sizeof(t_ant) * engine->nbr_ants);
	i = 0;
	while (i < engine->nbr_ants)
	{
		engine->ants[i] = create_ant(engine->nb_paths, i + 1);
		i++;
	}
	move_ants(engine);
}
