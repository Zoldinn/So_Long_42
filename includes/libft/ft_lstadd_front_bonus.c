/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:01:20 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/14 17:14:29 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* -- TESTS -- */

#include <stdio.h>

void	ft_print_lst(t_list *list)
{
	while (list != NULL)
	{
		printf("%s ", (char *) list->content);
		list = list->next;
	}
}

// // un peu overkill mais ca fonctionne
// void	free_lst(t_list *list)
// {
// 	t_list	*tmp;

// 	while (list != NULL)
// 	{
// 		tmp = list;
// 		list = list->next;
// 		free(tmp);
// 	}
// }


int	main(void)
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew("sword_1");
	new = ft_lstnew("sword_2");

	ft_lstadd_front(&head, new);

	free(head->next);
	free(head);
	return (0);
}
