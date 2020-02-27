#include "../includes/lem_in.h"

void	handle_errors_final(t_parse parser)
{
	if (parser.link_found == 0)
		general_error(MSG_NO_LINK);
}

void	errors_before_parsing_rooms_to_link(char *line, t_parse *parser)
{
	if (parser->start_found == 0)
		syntax_error(line, MSG_NO_START_ROOM, parser->nbr_line);
	if (parser->end_found == 0)
		syntax_error(line, MSG_NO_END_ROOM, parser->nbr_line);
}

void	handle_errors_rooms(char *line, char **parsed_line, t_parse *parser)
{
	if (ft_count_spaces(line) != 2)
		syntax_error(line, MSG_TOO_MUCH_SPACE, parser->nbr_line);
	if (ft_strchr(line, '\t'))
		syntax_error(line, MSG_ROOM_LINK, parser->nbr_line);
	if (parser->link_found)
		syntax_error(line, MSG_ROOM_AFTER_LINK, parser->nbr_line);
	if (ft_strchr(line, '-'))
		syntax_error(line, MSG_ROOM_HYPHEN, parser->nbr_line);
	if (line[0] == 'L')
		syntax_error(line, MSG_SETT_START_L, parser->nbr_line);
	verify_rooms_format(parsed_line, line, parser);
	if (rooms_contains_name(parsed_line[0], parser))
		syntax_error(line, MSG_SAME_NAME, parser->nbr_line);
	if (rooms_contains_coor(ft_atoi(parsed_line[1]),
		ft_atoi(parsed_line[2]), parser))
		syntax_error(line, MSG_SAME_COOR, parser->nbr_line);
}

void	syntax_error(char *line, char *explain, int nbline)
{
	ft_putstr_fd(RED"Syntax Error "NC, 2);
	ft_putstr_fd(explain, 2);
	ft_putstr_fd(CYAN" (on \"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\" at line ", 2);
	ft_putnbr_fd(nbline, 2);
	ft_putstr_fd(")\n", 2);
	exit(3);
}

void	general_error(char *explain)
{
	ft_putstr_fd(RED"General Error "NC, 2);
	ft_putendl_fd(explain, 2);
	exit(3);
}
