/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:46:33 by alzaynou          #+#    #+#             */
/*   Updated: 2020/02/12 07:44:22 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strndup(const char *str, char c)
{
	char	*nstr;
	int		cnt;

	nstr = NULL;
	cnt = 0;
	while (str[cnt] && str[cnt] != c)
		cnt++;
	if (!(nstr = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	while (cnt >= 0)
	{
		nstr[cnt] = str[cnt];
		cnt--;
	}
	return (nstr);
}
