/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:46 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/10 21:43:55 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 42

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// t_lst
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

// str1
int					ft_strlen(char *str);
int					ft_strslen(char **strs);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(char *s);
// str2
int					ft_instr(char const *str, char c);
void				ft_strreplace(char *str, char find, char replace);

// memory
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);

// strs
char				**ft_free_strs(char **strs);
char				**ft_split(char const *s, char c);

// print
int					ft_putstr_fd(char *str, int fd);
int					ft_print_fd(int fd, char *str, ...);

// t_lst / gnl utils
char				*ft_get_next_line(int fd);
t_list				*ft_lstnew(char *content);
int					ft_lstadd_back(t_list *lst, t_list *new);
t_list				*ft_lstclear(t_list *lst);
int					ft_instr2(char const *str, char c);

#endif