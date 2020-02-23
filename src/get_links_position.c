#include "../includes/lem_in.h"

int get_pos_link_out(char **out_links, char *in_link, int out_degree)
{
	int i;

	i = 0;
	if (out_links && in_link)
	{
		while (i < out_degree)
		{
			if (out_links[i] != NULL
			&& out_links[i][0] != '\0'
			&& ft_strequ(out_links[i], in_link))
				return (i);
			i++;
		}
	}
	return (-1);
}

int get_pos_link_in(char **in_links, char *out_link, int in_degree)
{
	int i;

	i = 0;
	if (in_links && out_link)
	{
		while (i < in_degree)
		{
			if (in_links[i] != NULL
			&& in_links[i][0] != '\0'
			&& ft_strequ(in_links[i], out_link))
				return (i);
			i++;
		}
	}
	return (-1);
}
