/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:03:07 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/12 00:00:52 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
*** includes
*/

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
*** macros
*/

# define BUFF_SIZE 2

int				get_next_line(const int fd, char **line);

/*
*** data sturct
*/

typedef struct			s_node
{
	char			*str;
	int			nfd;
	struct s_node		*next;
}				t_node;

#endif
