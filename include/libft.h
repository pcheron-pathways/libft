/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:46 by pcheron           #+#    #+#             */
/*   Updated: 2023/02/28 21:39:31 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// str1
int		ft_strlen(char *str);
int		ft_strslen(char **strs);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *s);
// str2
int		ft_instr(char const *str, char c, int l);


// memory
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

// strs
char	**ft_free_strs(char **strs, int j);
char	**ft_split(char const *s, char c);

// print
int		ft_putstr_fd(char *str, int fd);
int		ft_print_fd(int fd, char *str, ...);

// t_lst

#endif