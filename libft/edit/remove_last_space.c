/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last_sapce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:31:15 by alzaynou          #+#    #+#             */
/*   Updated: 2020/01/20 20:39:26 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		remove_last_sapce(char *str)
{
	int	cnt;

	cnt = ft_strlen(str) - 1;
	while (str[cnt] == ' ' || str[cnt] == '	')
		cnt--;
	str[cnt + 1] = '\0';
}
