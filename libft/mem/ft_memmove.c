/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 00:09:39 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/26 19:10:24 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *buf[len];

	if (len <= 65535)
	{
		ft_memcpy(buf, src, len);
		ft_memcpy(dst, buf, len);
	}
	return (dst);
}
