/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:57:38 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/11 15:43:22 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_gnl
{
	char			*string;
	int				readed;
	struct s_list	*next;
}					t_gnl;

char	*ft_get_next_line(int fd);
void	ft_free_list(t_gnl **list);
t_gnl	*ft_lst_last(t_gnl *list);
int		ft_strchr_gnl(char *str, char x);
t_gnl	*ft_lst_last(t_gnl *list);
int		ft_size_line(t_gnl *list);
char	*ft_get_line(t_gnl *list);
t_gnl	*ft_cut_list(t_gnl **list);
char	*ft_sub_str(char *str, int start);
void	*ft_calloc(size_t count, size_t size);

#endif