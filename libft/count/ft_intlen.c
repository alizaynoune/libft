#include "libft.h"

int	ft_intlen(long long int n)
{
	int			len;
	unsigned long long	nb;

	len = n < 0 ? 1 : 0;
	nb = n < 0 ? n * -1 : n;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
