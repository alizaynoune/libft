#include "libft.h"

void		ft_free_rev(void **tab, int len)
{
	while (len >= 0)
	{
		free(tab[len]);
		tab[len--] = NULL;
	}
	tab != NULL ? free(tab) : 0;
}
