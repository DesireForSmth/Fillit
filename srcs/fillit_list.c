/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:03:23 by mcarc             #+#    #+#             */
/*   Updated: 2019/11/21 18:15:56 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fillit_lstdelone(t_list **tmp)
{
	if (*tmp && tmp)
	{
		free((*tmp)->tetri);
		ft_memdel((void **)tmp);
	}
}

void		fillit_lstdel(t_list **head)
{
	t_list	*lst;
	t_list	*next_lst;

	if (head)
	{
		lst = *head;
		while (lst)
		{
			next_lst = lst->next;
			lst->next = NULL;
			fillit_lstdelone(&lst);
			lst = next_lst;
		}
		*head = NULL;
	}
}

t_list		*fillit_lstnew(char *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (!(tmp->tetri = malloc(sizeof(char) * 21)))
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp->tetri = ft_memcpy(tmp->tetri, content, 21);
	tmp->next = NULL;
	return (tmp);
}

int			fillit_lstpushback(t_list *head, char *content)
{
	t_list *tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = fillit_lstnew(content);
	return ((tmp->next) ? 1 : 0);
}

t_list		*fillit_lst(t_list **head, char *content)
{
	t_list	*tmp;

	if (!(*head))
	{
		tmp = fillit_lstnew(content);
		*head = tmp;
	}
	else if (!(fillit_lstpushback(*head, content)))
	{
		fillit_lstdel(head);
		return (0);
	}
	return (*head);
}
