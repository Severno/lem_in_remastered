#include "../../includes/libft.h"

void			ft_free_split_str(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		if ((*tab)[i] != NULL)
			free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = 0;
}
