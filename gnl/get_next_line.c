/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:48:07 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/22 14:41:27 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*find_fd(int fd, t_node *head)
{
	t_node *temp;

	temp = head;
	while (temp && temp->nfd != fd)
		temp = temp->next;
	return (temp);
}

t_node	*make_node(int fd, t_node *head)
{
	t_node *temp;
	t_node *newn;

	temp = head;
	newn = (t_node *)malloc(sizeof(t_node));
	newn->str = ft_strnew(0);
	newn->nfd = fd;
	newn->next = NULL;
	if (!head)
		return (newn);
	while (temp->next)
		temp = temp->next;
	temp->next = newn;
	return (newn);
}

int		get_line(char **line, t_node *temp)
{
	size_t	chk;
	char	*tmp;

	chk = 0;
	while (temp->str[chk] != '\n' && temp->str[chk] != '\0')
		chk++;
	if (!(temp->str[chk] == '\0' && chk == 0))
	{
		*line = ft_strsub(temp->str, 0, chk);
		chk = temp->str[chk] == '\n' ? chk + 1 : chk;
		tmp = temp->str;
		temp->str = ft_strdup(&temp->str[chk]);
		free(tmp);
		if (chk > 0)
			return (1);
	}
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_node	*head;
	char			buff[BUFF_SIZE + 1];
	t_node			*temp;
	int				red;
	char			*tmp;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!head)
		head = make_node(fd, head);
	if ((temp = find_fd(fd, head)) == NULL)
		temp = make_node(fd, head);
	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		tmp = temp->str;
		temp->str = ft_strjoin(temp->str, buff);
		free(tmp);
		if (ft_strchr(temp->str, 10))
			break ;
	}
	return (get_line(line, temp));
}
