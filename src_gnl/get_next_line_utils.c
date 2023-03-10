/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:27:34 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/05 17:39:13 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_instr2(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strtronc(char *s, unsigned int j)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i + j])
		i++;
	str = malloc(i + 1);
	if (!str)
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
	lst->content = ft_strtronc(lst->content, ft_instr2(lst->content, '\n'));
	if ((lst->content) == NULL || lst->content[0] == 0)
	{
		free(lst->content);
		free(lst);
		return (NULL);
	}
	return (lst);
}
