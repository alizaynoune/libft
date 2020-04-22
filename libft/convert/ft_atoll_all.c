#include "libft.h"

long long	ft_atoll_all(char *str)
{
	size_t	i;

	i = ft_skip_char(str, "\t ");
	str[i] == '-' || str[i] == '+' ? i += 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	i += ft_skip_char(&str[i], "\t ");
	if (str[i])
		return (0);
	return (ft_atoll(str));
}
