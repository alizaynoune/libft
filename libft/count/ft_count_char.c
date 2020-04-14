/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:10:42 by alzaynou          #+#    #+#             */
/*   Updated: 2020/02/12 10:13:16 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_char(char *str, char c)
{
	int		cnt;
	int		chr;

	cnt = 0;
	chr = 0;
	if (!str)
		return (0);
	while (str[cnt])
	{
		if (str[cnt] == c)
			chr++;
		cnt++;
	}
	return (chr);
}
