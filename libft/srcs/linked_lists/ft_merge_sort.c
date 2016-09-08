/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:34:22 by atamano           #+#    #+#             */
/*   Updated: 2015/02/06 13:34:23 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static t_list	*ft_st_mrg(t_list *a, t_list *b, int (*f)(void *, void *))
{
	t_list *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((*f)((void *)a->content, (void *)b->content) < 0)
	{
		result = a;
		result->next = ft_st_mrg(a->next, b, (*f));
	}
	else
	{
		result = b;
		result->next = ft_st_mrg(a, b->next, (*f));
	}
	return (result);
}

static void		ft_bf_split(t_list *source, t_list **frontref, t_list **backref)
{
	t_list	*fast;
	t_list	*slow;

	if (source == NULL || source->next == NULL)
	{
		*frontref = source;
		*backref = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*frontref = source;
		*backref = slow->next;
		slow->next = NULL;
	}
}

void			ft_merge_sort(t_list **begin, int (*f)(void *, void *))
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *begin;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_bf_split(head, &a, &b);
	ft_merge_sort(&a, (*f));
	ft_merge_sort(&b, (*f));
	*begin = ft_st_mrg(a, b, f);
}
