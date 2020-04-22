#include "libft.h"

size_t		ft_strnlen(char *str, char *c)
{
	size_t	len;

	len = 0;
	while (str[len] && !ft_strchr(c, str[len]))
		len++;
	return (len);
}
