#include "../includes/lem_in.h"

void		handle_command_start(char *line, t_parse *parser)
{
	if (parser->start_found)
		syntax_error(line, MSG_OVERRIDE_START, parser->nbr_line);
	ft_strdel(&line);
	handle_comments(&line, parser);
	if (!is_room(line, parser))
		syntax_error(line, MSG_NO_ROOM_START, parser->nbr_line);
	parse_room(line, parser, 1, 0);
	parser->start_found = 1;
}

void		handle_command_end(char *line, t_parse *parser)
{
	if (parser->end_found)
		syntax_error(line, MSG_OVERRIDE_END, parser->nbr_line);
	ft_strdel(&line);
	handle_comments(&line, parser);
	if (!is_room(line, parser))
		syntax_error(line, MSG_NO_ROOM_END, parser->nbr_line);
	parse_room(line, parser, 0, 1);
	parser->end_found = 1;
}
