/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:32:42 by pcheron           #+#    #+#             */
/*   Updated: 2022/12/09 13:03:20 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*assembling(t_list *lst, int i)
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
		l += instr(temp->content, '\n', 1);
		temp = temp->next;
	}
	str = malloc(l + 1);
	if (str == NULL)
		return (NULL);
	l = -1;
	while (lst != NULL)
	{
		i = -1;
		while (++i < instr(lst->content, '\n', 1))
			str[++l] = lst->content[i];
		lst = lst->next;
	}
	return (str[l + 1] = 0, str);
}

char	*gnl_le_retour(t_list *lst, char *buffer, int reader, int fd)
{
	t_list	*t;

	t = lst;
	while (!instr(t->content, '\n', 0))
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

char	*get_next_line(int fd)
{
	char			*buffer;
	int				reader;
	char			*r;
	static	t_list	*(lst[1024]);

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
	if (gnl_le_retour(lst[fd], buffer, reader, fd) == NULL)
		return (NULL);
	r = assembling(lst[fd], 0);
	return (lst[fd] = ft_lstclear(lst[fd]), r);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	//int fd2;
// 	//fd = 0; // entree standard
// 	fd = open("myfile3.txt", O_RDONLY);
// 	// fd2 = open("myfile4.txt", O_RDONLY);
// 	do
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 	} while (str != NULL);
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	return (0);
// }
