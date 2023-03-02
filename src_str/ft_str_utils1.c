/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:10:08 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/01 00:48:43 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s) + 1);
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

int	ft_strslen(char **strs)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (strs[i])
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	while (strs[i])
		i++;
	str = malloc(ft_strslen(strs) + (ft_strlen(sep) * (i - 1) * (i != 0)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			str[k] = strs[i][j];
			j++;
			k++;
		}
		i++;
		if (strs[i])
		{
			j = 0;
			while (sep[j])
			{
				str[k] = sep[j];
				j++;
				k++;
			}
		}
	}
	str[k] = 0;
	return (str);
}
