/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:57:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/31 17:39:39 by ageiser          ###   ########.fr       */
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
