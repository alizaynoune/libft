#include "libft.h"

int	ft_power(int nbr, int power)
{
	int	sum;

	sum = nbr;
	if (power == 0)
		return (1);
	while (--power > 0)
		sum *= nbr;
	return (sum);
}
