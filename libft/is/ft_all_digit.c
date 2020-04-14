/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:07:25 by alzaynou          #+#    #+#             */
/*   Updated: 2020/02/12 10:32:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_all_digit(char *str)
{
	int		cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt])
	{
		if (str[cnt] > '9' || str[cnt] < '0')
			return (0);
		cnt++;
	}
	return (1);
}
