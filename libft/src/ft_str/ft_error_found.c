#include "../../includes/libft.h"

void		ft_error_found(char *str)
{
	ft_putendl_fd(str, 2);
	exit(3);
}