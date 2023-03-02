/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:47:26 by pcheron           #+#    #+#             */
/*   Updated: 2022/12/05 17:37:29 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strtronc(char *s, unsigned int j)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i + j])
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[j + i])
	{
		str[i] = s[j + i];
		i++;
	}
	str[i] = 0;
	free(s);
	return (str);
}

char	*ft_strdup(char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (instr(s, '\0', 1) == 0)
		return (free(s), NULL);
	str = malloc(instr(s, '\0', 1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = ft_strdup(content);
	if (lst->content == NULL)
	{
		free(lst);
		return (NULL);
	}
	lst->next = NULL;
	return (lst);
}

int	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		lst = new;
	else
	{
		temp = lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return (1);
	}
	return (0);
}

t_list	*ft_lstclear(t_list *lst)
{
	t_list	*t;

	t = lst;
	if (lst == NULL)
		return (NULL);
	while (t->next != NULL)
	{
		t = lst->next;
		free(lst->content);
		free(lst);
		lst = t;
	}
	lst->content = ft_strtronc(lst->content, instr(lst->content, '\n', 1));
	if ((lst->content) == NULL || lst->content[0] == 0)
	{
		free(lst->content);
		free(lst);
		return (NULL);
	}
	return (lst);
}
