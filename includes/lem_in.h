#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "./error_code.h"

# define NB_PATHS_COLORS 4
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"

# define RED "\x1B[31m"
# define CYAN "\x1b[36m"
# define NC "\033[0m"
# define BUFFER_SIZE 100000

typedef struct			s_room_parse
{
	int					x;
	int					y;
	int					end;
	int					start;
	char				*name;
	struct s_room_parse	*next;
}						t_room_parse;

typedef struct			s_room
{
	int					*paths;
	int					start;
	int					end;
	int					nb_paths;
	int					dist;
	int					blocked;
	char				*name;
}						t_room;

typedef struct			s_ant
{
	int					path_chosen;
	int					cur_pos;
}						t_ant;

typedef	struct			s_engine
{
	int					nbr_ants;
	int					nb_rooms;
	t_room				*rooms;
	int					**paths;
	int					nb_paths;
	int					debug;
	int					color;
	t_ant				*ants;
}						t_engine;

typedef struct			s_parse
{
	int					nbr_ants;
	int					nbr_line;
	int					nb_rooms;
	int					start_found;
	int					end_found;
	int					link_found;
	int					color;
	char				*buffer;
	int					bytes;
	int					mult;
	t_room_parse		*room;
	t_room				*rooms;
}						t_parse;

/*
** Parse
*/

int						parse_ants(char *str);
void					parse_room(char *line,
							t_parse *parser, int start, int end);
void					parse_command(char *line, t_parse *parser);
void					parse_rooms_to_link(char *line, t_parse *parser);
t_room					parse_room_from_chained_list(t_room_parse *old_room,
							t_parse *parser);
void					parse_link(char *line, t_parse *parser);
void					handle_comments(char **line, t_parse *parser);

/*
** Verify
*/

int						is_room(char *line, t_parse *parser);
int						is_link(char *line, t_parse *parser);
int						is_command(char *line);
int						is_comment(char *line);
void					verify_rooms_format(char **splited_s,
							char *line, t_parse *parser);
int						rooms_contains_name(char *name, t_parse *parser);
int						rooms_contains_coor(int x, int y, t_parse *parser);

/*
** Errors handling
*/

void					handle_errors_rooms(char *line,
							char **parsed_line, t_parse *parser);
void					syntax_error(char *line, char *explain, int nbline);
void					errors_before_parsing_rooms_to_link(char *line,
							t_parse *parser);
void					handle_errors_final(t_parse parser);
void					general_error(char *explain);

/*
** Utils
*/

int						read_line(char **line, t_parse *parser);
void					init_parser(t_parse *parser);
void					verify_that_link_does_not_already_exists(char *line,
							t_room room, int index, t_parse *parser);
void					ft_error_found(char *str);
int						len_of_link(char **link);

/*
** Buffer
*/

void					add_to_buffer(char *line, t_parse *parser);
void					print_buffer(t_parse *parser);

/*
** Commands
*/

void					handle_command_start(char *line, t_parse *parser);
void					handle_command_end(char *line, t_parse *parser);

/*
** Display
*/

void					display_engine(t_engine engine);

/*
** Engine
*/

void					start_engine(t_engine *engine);
int						used_room(t_engine *engine, int i_room);
int						get_next_room(t_engine *engine, int i_room);

/*
** Debug
*/

void					display_paths(t_engine *engine);
char					*get_color(int i_path);

/*
** Moving
*/

void					init_ants(t_engine *engine);
int						continue_moving(t_engine *engine);
int						get_index_lower(int nb_paths, int ant_nb);

/*
 * copy_lines
 */
char					*lem_strcat(char *s1, const char *s2, int *bytes);
char					*concat_buffer(char *dst, char *src, int *bytes, int *mult);

#endif
