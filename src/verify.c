#include "../includes/lem_in.h"

int		is_comment(char *line)
{
	return (*line && line[0] == '#' && line[1] != '#');
}

int		is_command(char *line)
{
	return (*line && line[0] == '#' &&
		line[1] == '#' && ft_strlen(line + 2) > 0);
}

int		is_room(char *line, t_parse *parser)
{
	char	**parsed_line;
	int		len;

	if (line[0] == '#')
		return (0);
	parsed_line = ft_strsplit(line, ' ');
	len = len_of_link(parsed_line);
	if (len != 3)
	{
		if (len > 3)
			syntax_error(line, MSG_UNKNOWN_SETTING, parser->nbr_line);
		ft_free_split_str(&parsed_line);
		return (0);
	}
	handle_errors_rooms(line, parsed_line, parser);
	ft_free_split_str(&parsed_line);
	return (1);
}

int		is_link(char *line, t_parse *parser)
{
	char	**parsed_line;
	int		len;

	if (line[0] == '#')
		return (0);
	parsed_line = ft_strsplit(line, '-');
	len = len_of_link(parsed_line);
	if (len != 2)
	{
		ft_free_split_str(&parsed_line);
		return (0);
	}
	if (ft_strequ(parsed_line[0], parsed_line[1]))
		syntax_error(line, MSG_LINK_SAME, parser->nbr_line);
	ft_free_split_str(&parsed_line);
	return (1);
}
