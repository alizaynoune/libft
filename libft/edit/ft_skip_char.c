#include"libft.h"

size_t		ft_skip_char(char *str, char *c)
{
	size_t	i;

	i = 0;
	while (str[i] && (ft_strchr(c, str[i])))
		i++;
	return (i);
}
