/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:16:33 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/28 11:59:35 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*ft_lstnew(long int nb, int i)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->index = i;
	node->push_cost = 0;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	else if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
	lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}
/*
#include <stdio.h>//WATCH OUT YOU USE A FORBIDDEN FUNCTION
void print_list(t_list *stack_a, t_list *stack_b)
{
    while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_b && stack_a)
		{
			printf("| %li  :  %u |     | %li  :  %u |\n", stack_a->nb,
					stack_a->index, stack_b->nb, stack_b->index);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a)
		{
			printf("| %li  :  %u |\n", stack_a->nb,	stack_a->index);
			stack_a = stack_a->next;
		}
		else if (stack_b)
		{
			printf("                | %li  :  %u |\n", stack_b->nb,
					stack_b->index);
			stack_b = stack_b->next;
		}
    }
}*/
