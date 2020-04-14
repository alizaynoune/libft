/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:17:21 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/26 19:12:20 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl(char const *s)
{
	size_t cnt;

	cnt = 0;
	if (s)
	{
		while (s[cnt] != '\0')
			ft_putchar(s[cnt++]);
		ft_putchar('\n');
	}
}
