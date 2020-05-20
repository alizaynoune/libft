#include "libft.h"

int	len_value(int value, int base)
{
	int	len;

	len = value < 0 && base == 10 ? 1 : 0;
	value = value < 0 ? -value : value;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*get_sum(char *sum, int len, int value, int base)
{
	int	sign;

	sign = value < 0 && base == 10 ? 1 : 0;
	value = value < 0 ? -value : value;
	while (value)
	{
		if (value % base >= 10)
			sum[len--] = ((value % base) - 10) + 'a';
		else
			sum[len--] = (value % base) + '0';
		value /= base;
	}
	sign == 1 ? sum[0] = '-' : 0;
	return (sum);
}

char	*ft_itoa_base(int value, int base)
{
	char	*sum;
	int	len;

	if (base >= 2 && base <= 16)
	{
		len = len_value(value, base);
		if (!(sum = (char *)ft_memalloc(len + 1)))
			return (NULL);
		return (get_sum(sum, --len, value, base));
	}
	return (NULL);
}
