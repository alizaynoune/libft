#include "libft.h"

static	void	helper(int **tab, char *str, char *c)
{
	size_t	i;
	int	words;
	int	len;

	i = 0;
	words = 1;
	while (str[i])
	{
		if ((len = ft_strnlen(&str[i], c)))
		{
			tab[words][0] = i;
			tab[words++][1] = len;
			i += len;
		}
		else
			i++;
	}
}

int		**start_end_words(char *str, char *c)
{
	size_t	i;
	size_t	words;
	int	**tab;

	i = 0;
	words = count_words(str, c);
	if (!words || !(tab = (int **)malloc(sizeof(int *) * (words + 1))))
		return (NULL);
	while (i <= words)
		if (!(tab[i++] = (int *)malloc(sizeof(int) * 2)))
		{
			ft_free_rev((void **)tab, i - 2);
			return (NULL);
		}
	tab[0][0] = words;
	tab[0][1] = words;
	helper(tab, str, c);
	return (tab);
}
