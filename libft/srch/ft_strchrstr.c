#include "libft.h"

int	ft_strchrstr(char *str, char *c)
{
	size_t		i;

	i = 0;
	while (c[i])
		if (!ft_strchr(str, c[i++]))
			return (0);
	return (1);
}
