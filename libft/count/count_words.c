/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 02:42:25 by alzaynou          #+#    #+#             */
/*   Updated: 2020/01/20 02:45:35 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_words(char *str, char *c)
{
	size_t		i;
	int		words;
	char		*chr;

	i = 0;
	words = 0;
	while (str[i])
	{
		chr = ft_strchr(c, str[i]);
		if (!chr && (ft_strchr(c, str[i + 1]) || !str[i + 1]))
			words++;
		if (chr)
			i += ft_skip_char(&str[i], c);
		else
			i++;
	}
	return (words);
}
