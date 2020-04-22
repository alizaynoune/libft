#include "libft.h"

static void	copy_words(char **tab, char *str, int **l_w)
{
	int	i;

	i = 0;
	while (i < l_w[0][0])
	{
		tab[i] = ft_strncpy(tab[i], &str[l_w[i + 1][0]], l_w[i + 1][1]);
		tab[i][l_w[i + 1][1]] = '\0';
		i++;
	}
}

char		**ft_split_by_str(char *str, char *c)
{
	char		**tab;
	int		n_words;
	int		**l_w;
	int		i;

	n_words = count_words(str, c);
	i = -1;
	if (!n_words || !(tab = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return (NULL);
	tab[n_words] = NULL;
	l_w = start_end_words(str, c);
	while (++i < l_w[0][0])
		if (!(tab[i] = (char *)malloc(sizeof(char) * (l_w[i + 1][1] + 1))))
		{
			ft_free_rev((void **)tab, i - 1);
			ft_free_rev((void **)l_w, l_w[0][0]);
			return (NULL);
		}
	copy_words(tab, str, l_w);
	ft_free_rev((void **)l_w, l_w[0][0]);
	return (tab);
}
