#include "../includes/lem_in.h"

static void		read_flags(t_parse *parser, int av, char **ac)
{
	int		i;

	i = 1;
	while (i < av)
	{
		if (ft_strequ("--color", ac[i]))
			parser->color = 1;
		else
			syntax_error(ac[i], MSG_UNKNOWN_FLAG, 0);
		i++;
	}
}

/*
** Free the parse structure and create the engine structure
*/

static t_engine	get_engine(t_parse *parser)
{
	t_engine		engine;
	t_room_parse	*tmp;
	t_room_parse	*fst;

	engine.nbr_ants = parser->nbr_ants;
	engine.nb_rooms = parser->nb_rooms;
	engine.rooms = parser->rooms;
	engine.color = parser->color;
	engine.nb_paths = 0;
	fst = parser->room;
	while (fst)
	{
		tmp = fst->next;
		ft_memdel((void **)&fst);
		fst = tmp;
	}
	parser->room = NULL;
	return (engine);
}

static void		parse_line(char *line, t_parse *parser)
{
	if (is_command(line))
		parse_command(line, parser);
	else if (is_room(line, parser))
		parse_room(line, parser, 0, 0);
	else if (is_link(line, parser))
	{
		if (!parser->link_found)
			parse_rooms_to_link(line, parser);
		parse_link(line, parser);
	}
	else if (!is_comment(line))
		syntax_error(line, MSG_UNKNOWN_SETTING, parser->nbr_line);
	else if (is_comment(line))
		ft_strdel(&line);
}

static void		parse(t_parse *parser)
{
	char *line;

	handle_comments(&line, parser);
	parser->nbr_ants = parse_ants(line);
	ft_strdel(&line);
	while (read_line(&line, parser) > 0)
		parse_line(line, parser);
}

int				main(int av, char **ac)
{
	t_parse		parser;
	t_engine	engine;

	init_parser(&parser);
	read_flags(&parser, av, ac);
	parse(&parser);
	handle_errors_final(parser);
	print_buffer(&parser);
	engine = get_engine(&parser);
	start_engine(&engine);
	return (0);
}
