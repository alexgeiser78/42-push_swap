/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:57:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/13 18:17:59 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *sa(t_list *lst)
{
	int swap;
			
	if(lst == NULL || lst->next ==NULL)
		return(0);
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
	return(lst);
}
/* on stocke dans swap le data du premier element, le data du permier element prend le data du 
deuxieme element, le deuxieme element prend le data de swap soit premier element */ 

//-----------------------------------------------------------------

t_list *sb(t_list *lst)
{
	int swap;

	if(lst == NULL || lst->next ==NULL)
		return(0);
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
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
/*	printf("---------------------\n"); 
	printf("pointeur de debut de chaine = %p\n", &listb);
	printf("1-> tmp = %p\n", tmp);	
*/
(*listb)->next = *lista;
/*	printf("-----------------\n");
	printf("2\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");
*/
*lista = *listb;
/*
	printf("-----------------\n");
	printf("3\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");
*/
*listb = tmp;
/*	printf("-----------------\n");
	printf("4\n");
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n");
*/
return;

}
//on stocke dans tmp le deuxieme element de la liste b, qui a la fin sera le premier
//le premier element de la liste a pointe sur la liste b
//on copie la liste b dans la liste a
//dans la liste b on remet le deuxieme element qui etait en tampon

//-------------------------------------------


void pb(t_list **lista, t_list **listb)
{
t_list *tmp;

if (*lista == NULL)
	return;
	tmp = (*lista)->next;
	(*lista)->next = *listb;
	*listb = *lista;
	*lista = tmp;
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
