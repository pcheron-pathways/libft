/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:30:35 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/04 17:43:06 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

static int	ft_arg_len(char c, va_list args)
{
	if (c == 's')
		return (ft_strlen(va_arg(args, char *)));
	else if (c == 'c')
		return (1);
	return (-1);
}

static char	*ft_malloc_print(char *str, va_list args)
{
	int	i;
	int	size;
	int	size_arg;

	i = 0;
	size = 0;
	size_arg = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			size_arg = ft_arg_len(str[i], args);
			if (size_arg < 0)
				return (NULL);
			size += size_arg;
		}
		else
			size++;
		i++;
	}
	// printf("size : %i\n", size);
	return ((char *)malloc(size + 1));
}

int	ft_strconcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = ft_strlen(str1);
	j = 0;
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	return (j);
}

int	ft_add_arg(char *print, char c, va_list args)
{
	int	r;

	r = 0;
	if (c == 's')
		return (ft_strconcat(print, va_arg(args, char *)));
	else if (c == 'c')
		print[ft_strlen(print)] = va_arg(args, int);
	return (1);
}

void	ft_setup_print(char *print, char *str, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print[j] = 0;
			i++;
			j += ft_add_arg(print, str[i], args);
		}
		else
		{
			print[j] = str[i];
			j++;
		}
		i++;
	}
	print[j] = 0;
}

int	ft_print_fd(int fd, char *str, ...)
{
	va_list	args;
	char	*print;
	int		i;
	int		r;

	i = 0;
	if (fd < 0 || fd >= 1024)
		return (-1);
	va_start(args, str);
	print = ft_malloc_print(str, args);
	if (!print)
		return (-1);
	va_end(args);
	va_start(args, str);
	ft_setup_print(print, str, args);
	va_end(args);
	r = ft_putstr_fd(print, fd);
	free(print);
	return (r);
}

// int main()
// {
// 	int i;

// 	i =	ft_print_fd(1, "salut %s, %s\n", "toi", "moi");
// 	printf("%d", i);
// 	return (0);
// }
