#include "libft.h"

void		ft_free_tab_char(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}
