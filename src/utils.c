/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:59:56 by sapril            #+#    #+#             */
/*   Updated: 2020/02/27 16:59:56 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	verify_that_link_does_not_already_exists(char *line, t_room room,
	int index, t_parse *parser)
{
	int		i;

	i = 0;
	while (i < room.nb_paths)
	{
		if (room.paths[i] == index)
			syntax_error(line, MSG_LINK_ALREADY_EXISTS, parser->nbr_line);
		i++;
	}
}

int		read_line(char **line, t_parse *parser)
{
	int		res;

	parser->nbr_line++;
	res = get_next_line(0, line);
	if (res == -1 && parser->nbr_line == 1)
	{
		ft_putendl_fd("Read Error on open", 2);
		exit(3);
	}
	if (res == -1)
	{
		ft_putstr_fd("Read Error : ", 2);
		ft_putstr_fd("\" at line ", 2);
		ft_putnbr_fd(parser->nbr_line, 2);
		exit(3);
	}
	parser->buffer = concat_buffer(parser->buffer, *line, &parser->bytes, &parser->mult);
	return (res);
}

void	init_parser(t_parse *parser)
{
	parser->nbr_line = 0;
	parser->nbr_ants = 0;
	parser->start_found = 0;
	parser->end_found = 0;
	parser->color = 0;
	parser->link_found = 0;
	parser->room = NULL;
	parser->nb_rooms = 0;
	parser->buffer = ft_strnew(100000);
	parser->bytes = 0;
	parser->mult = 1;
}

void		ft_error_found(char *str)
{
	ft_putendl_fd(str, 2);
	exit(3);
}

int			len_of_link(char **link)
{
	int i;

	i = 0;
	while (link[i])
		i++;
	return (i);
}