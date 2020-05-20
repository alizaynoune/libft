#include "libft.h"

int	check_digit_base(const char *str, int base)
{
	int	i;
	int	nbr;

	i = str[0] == '-' || str[0] == '+' ? 1: 0;
	while (str[i])
	{
		if (str[i] >= 'a' || str[i] >= 'A')
			nbr = str[i] >= 'a' ? (str[i] - 'a') + 10 : (str[i] - 'A') + 10;
		else
			nbr = str[i] - '0';
		if (nbr >= base)
			return (0);
		i++;
	}
	return (1);
}

int	to_base(const char *str, int base)
{
	int	power;
	int	i;
	int	num;
	int	nbr;

	i = 0;
	power = -1;
	num = 0;
	while (str[i++]);
	i--;
	while (--i > -1 && str[i] != '-' && str[i] != '+')
	{
		if (str[i] >= 'a' || str[i] >= 'A')
			nbr = str[i] >= 'a' ? (str[i] - 'a') + 10: (str[i] - 'A') + 10;
		else
			nbr = (str[i] - '0');
		num += (ft_power(base , ++power) * nbr);
	}
	return (str[0] == '-' ? -num : num);
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base >= 1 && str_base <= 16 && str)
	{
		if (!check_digit_base(str, str_base))
			return (0);
		return (to_base(str, str_base));
	}
	return (0);
}
