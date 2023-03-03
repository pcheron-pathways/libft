/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:18:18 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/03 14:17:14 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// char	*ft_assembling(t_list *lst, int i)
// {
// 	int		l;
// 	char	*str;
// 	t_list	*temp;

// 	l = 0;
// 	if (lst == NULL)
// 		return (NULL);
// 	temp = lst;
// 	while (temp != NULL)
// 	{
// 		l += instr(temp->content, '\n', 1);
// 		temp = temp->next;
// 	}
// 	str = malloc(l + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	l = -1;
// 	while (lst != NULL)
// 	{
// 		i = -1;
// 		while (++i < instr(lst->content, '\n', 1))
// 			str[++l] = lst->content[i];
// 		lst = lst->next;
// 	}
// 	return (str[l + 1] = 0, str);
// }
