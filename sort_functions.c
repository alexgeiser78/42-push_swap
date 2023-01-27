/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:57:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/27 18:09:27 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *sa(t_list *lst)
{
	int swap;
	t_list *tmp;
	tmp = lst;

	if(list_size(lst) <= 1)
	{
		printf("A: 1 element or less\n"); // printf
		return(0);
	}
	else
	{
		swap = lst->data;
		lst->data = lst->next->data;
		lst->next->data = swap;
		lst= tmp;
	}
	return(lst);
}

//-----------------------------------------------------------------


t_list *sb(t_list *lst)
{
	int swap;
	t_list *tmp;
	tmp = lst;

	if(list_size(lst) <= 1)
	{
		printf("B: 1 element or less\n"); // printf
		return(0);
	}
	else
	{
		swap = lst->data;
		lst->data = lst->next->data;
		lst->next->data = swap;
		lst= tmp;
	}
	return(lst);
}

//-----------------------------------------------------------------

void *ss(t_list *lista, t_list *listb)
{
	lista = sa(lista);
	listb = sb(listb);
	return(0);
}

//-----------------------------------------------------------------

void *pa(t_list *lista, t_list *listb)
{
	int i = list_size(listb);
	int tmp;
       	tmp = listb->data;
	free_at(listb, i);
	lista = add_at(lista, tmp, i);
	return(0);
}
