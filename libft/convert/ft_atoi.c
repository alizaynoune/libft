/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:04:23 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/26 18:49:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		sum;
	int		sing;

	i = ft_skip_char((char *)str, "\t ");
	sum = 0;
	sing = str[i] == '-' ? -1 : 1;
	str[i] == '-' || str[i] == '+' ? i += 1 : 0;
	while (ft_isdigit(str[i]))
		sum = sum * 10 + (str[i++] - '0');
	return (sum * sing);
}
