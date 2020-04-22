#include "libft.h"

long long	ft_atoll(char *str)
{
	long long	sum;
	short		sing;
	size_t		i;

	sum = 0;
	if (!str)
		return (0);
	i = ft_skip_char(str, "\t ");
	sing = str[i] == '-' ? -1 : 1;
	str[i] == '-' || str[i] == '+' ? i += 1: 0;
	while (ft_isdigit(str[i]))
		sum = (sum * 10) + (str[i++] - '0');
	return (sum * sing);
}
