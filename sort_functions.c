/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:57:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/11 16:53:42 by ageiser          ###   ########.fr       */
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

void pa(t_list **lista, t_list **listb)
{
t_list *tmp;

if (*listb == NULL)
	return;
tmp = (*listb)->next;
	printf("---------------------\n"); 
	printf("1-> tmp = %p\n", tmp);
(*listb)->next = *lista;
/*	printf("---------------\n");
	printf("2\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");*/
*lista = *listb;
/*	printf("-----------------\n");
	printf("3\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");*/
*listb = tmp;
/*	printf("-----------------\n");
	printf("4\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");*/
return;

}
// necessite d'un double pointeur pour pouvoir modifier la memoire

//-------------------------------------------


void pb(t_list **lista, t_list **listb)
{
t_list *tmp;

if (*lista == NULL)
	return;
tmp = (*lista)->next;
	printf("---------------------\n"); 
	printf("1-> tmp = %p\n", tmp);
(*lista)->next = *listb;
/*	printf("---------------\n");
	printf("2\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");*/
*listb = *lista;
/*	printf("-----------------\n");
	printf("3\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");*/
*lista = tmp;
/*	printf("-----------------\n");
	printf("4\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");*/
return;
}

//-----------------------------------------------

void ra(t_list **lst)
{
	int swap = (*lst)->data;
	int last = list_size(*lst);

	add_at(*lst, swap, last);
	free_at(lst, 0);
}

//------------------------------------------------


void rb(t_list **lst)
{
	int swap = (*lst)->data;
	int last = list_size(*lst);

	add_at(*lst, swap, last);
	free_at(lst, 0);
}

//-------------------------------------------------

void rr(t_list **lista, t_list **listb)
{
	ra(lista);
	rb(listb);
}

//-------------------------------------------------


t_list *get_last(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//--------------------------------------------------

t_list *get_penultieme(t_list *lst)
{
	while (lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

//-------------------------------------------------

void rra(t_list **lst)
{
	t_list *tmp = *lst;
	t_list *last;
	t_list *penultieme;

		last = get_last(*lst);
		penultieme = get_penultieme(*lst);
		tmp = *lst;
		*lst = last;
		(*lst)->next = tmp;
		penultieme->next = NULL;		 
}

//-------------------------------------------------

void rrb(t_list **lst)
{
	t_list *tmp = *lst;
	t_list *last;
	t_list *penultieme;

		last = get_last(*lst);
		penultieme = get_penultieme(*lst);
		tmp = *lst;
		*lst = last;
		(*lst)->next = tmp;
		penultieme->next = NULL;
}

//-------------------------------------------------

void rrr(t_list **lista, t_list **listb)
{
	rra(lista);
	rrb(listb);
}
