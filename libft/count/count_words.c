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

#include "../includes/libft.h"

int			count_words(char *str, char c)
{
	int	cnt;
	int words;

	cnt = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[cnt])
	{
		if (str[cnt] != c && (str[cnt + 1] == c || !str[cnt + 1]))
			words++;
		cnt++;
	}
	return (words);
}
