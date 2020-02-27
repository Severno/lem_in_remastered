#include "../../includes/libft.h"

int			ft_count_spaces(char *str)
{
	int			blanks;

	blanks = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
			blanks++;
		str++;
	}
	return (blanks);
}
