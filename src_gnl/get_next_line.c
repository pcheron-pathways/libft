/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:22:30 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/10 21:43:29 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_assembling(t_list *lst, int i)
{
	int		l;
	char	*str;
	t_list	*temp;

	l = 0;
	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp != NULL)
	{
		l += ft_instr2(temp->content, '\n');
		temp = temp->next;
	}
	str = malloc(l + 1);
	if (str == NULL)
		return (NULL);
	l = -1;
	while (lst != NULL)
	{
		i = -1;
		while (++i < ft_instr2(lst->content, '\n'))
			str[++l] = lst->content[i];
		lst = lst->next;
	}
	return (str[l + 1] = 0, str);
}

static char	*ft_gnl_le_retour(t_list *lst, char *buffer, int reader, int fd)
{
	t_list	*t;

	t = lst;
	while (!ft_instr(t->content, '\n'))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (free(buffer), NULL);
		if (reader == 0)
			break ;
		buffer[reader] = 0;
		ft_lstadd_back(lst, ft_lstnew(buffer));
		t = t->next;
		if (t->content == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	return ("jusqu'ici, tout va bien");
}

char	*ft_get_next_line(int fd)
{
	char	*buffer;
	int		reader;
	char	*r;

	static t_list *(lst[1024]);
	reader = 0;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (lst[fd] == NULL)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == 0 || reader == -1)
			return (free(buffer), NULL);
		buffer[reader] = 0;
		lst[fd] = ft_lstnew(buffer);
		if (lst[fd] == NULL)
			return (free(buffer), NULL);
	}
	if (ft_gnl_le_retour(lst[fd], buffer, reader, fd) == NULL)
		return (NULL);
	r = ft_assembling(lst[fd], 0);
	return (lst[fd] = ft_lstclear(lst[fd]), r);
}
