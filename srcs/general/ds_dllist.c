/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_dllist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:51:25 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 10:51:54 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_dllist.h"

t_dllist	*ft_dllist_new_node(int value)
{
	t_dllist	*new_node;

	new_node = (t_dllist *)malloc(sizeof(t_dllist));
	if (new_node)
	{
		new_node->val = value;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return (new_node);
}

void	ft_dllist_push_front(t_dllist **head, int value)
{
	t_dllist	*new_node;

	new_node = ft_dllist_new_node(value);
	if (new_node)
	{
		if (!(*head))
			*head = new_node;
		else
		{
			(*head)->prev = new_node;
			new_node->next = *head;
			*head = new_node;
		}
	}
}

void 	ft_dllist_push_back(t_dllist **head, int value)
{
	t_dllist	*new_node;
	t_dllist	*back;

	new_node = ft_dllist_new_node(value);
	if (new_node)
	{
		if (!*head)
			*head = new_node;
		else
		{
			back = *head;
			while (back->next)
				back = back->next;
			back->next = new_node;
			new_node->prev = back;
		}
	}
}

void 	ft_dllist_del_node(t_dllist **head, t_dllist *to_del)
{
	if (*head && to_del)
	{
		if (*head == to_del)
			*head = (*head)->next;
		if (to_del->prev)
			to_del->prev->next = to_del->next;
		if (to_del->next)
			to_del->next->prev = to_del->prev;
		free(to_del);
	}
}

void	ft_dllist_print(t_dllist *it, int reverse)
{
	while (it && !reverse)
	{
		write(1, "|", 1);
		ft_putnbr_fd(it->val, 1);
		write(1, "|\n", 2);
		it = it->next;
	}
	while (it && reverse)
	{
		write(1, "|", 1);
		ft_putnbr_fd(it->val, 1);
		write(1, "|\n", 2);
		it = it->prev;
	}
}
