/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/18 18:41:19 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//--------------------------------------------------


int	is_bigger(t_list *lista)
{
	int big;

	big  = lista->data;
	while (lista)
	{
		if (lista->data > big)
			big = lista->data;
		lista = lista->next;
	}
	return(big);
}
//search for the biggest number to reduce the number of steps
//using a simple swap rule
//-------------------------------------------------------------------

void	sort_3(t_list **lista)
{
	int	biggest;

	biggest = is_bigger(*lista);
	if ((*lista)->data == biggest)
		run_rot_a(lista);
	else if ((*lista)->next->data == biggest)
		run_rev_rot_a(lista);
	if ((*lista)->data > (*lista)->next->data)
		run_swap_a(lista);
}

//function to sort 3 numbers using the less steps possiblei
//line 39 we earch for the biggest number
//line 40 if the biggest number is on top we put it on the base
//line 42 if the second number is the biggest we put the base on top
//line 44 if the first number is higher than the second we swap 
//the two first
//--------------------------------------------------

int	search_middle(t_list **lst)
{
	int add;
	int i;
	int med;
	t_list *tmp;

	i = 1;
	med = 0;
	tmp = (*lst);
	add = (*lst)->data;
	while((*lst)->next)
	{	
		(*lst) = (*lst)->next;

		add = add + (*lst)->data;
		i++;
 	}
	*lst = tmp;
	med = add / i;
//	printf("med = %d\n", med);//
	return(med);
}

//--------------------------------------------------------------------
void	sort_all(t_list **lista, t_list **listb)
{
	int medium;
	int i = 0;
	int stack_size_a;
	int stack_size_b;
	int chunk_is;

	chunk_is = 1;
	stack_size_a = list_size(*lista);
	while(stack_size_a > 2)
	{
//		printf("stack_size_a = %d\n", stack_size_a);//printf
//		printf("search_middle\n"); //printf
		medium = search_middle(lista);
		while(i != stack_size_a)
		{	
		if ((*lista)->data < medium)
			{
				(*lista)->chunk = chunk_is;
//				printf("top elem. data = %d\n", (*lista)->data);//
//				printf("top elem. index = %d\n", (*lista)->index);//
//				printf("top elem. chunk = %d\n", (*lista)->chunk);//
				pb(lista, listb);
			}
		else
			run_rot_a(lista);
		i++;
		}
//	printf("\n");//

//	printf("chunking %d done\n", chunk_is); //
	chunk_is++;
	i = 0;
	stack_size_a = list_size(*lista);
//	print_list(*lista); //
//	printf("A\n"); //
//	print_list(*listb); //
//	printf("B\n\n"); //

	}
//	printf("numbero %d, indice %d\n", (*listb)->data, (*listb)->index);
//	printf("numbero %d, indice %d\n", (*listb)->next->data, (*listb)->next->index);
	if (stack_size_a > 1 &&(*lista)->data > (*lista)->next->data)
				run_swap_a(lista);
	
	printf("\nchunked and pushed\n\n");//
	print_list(*lista); //
	printf("A\n"); //
	print_list(*listb); //
	printf("B\n\n"); //
/*	
	while(*listb)
	{
		printf("chunk = %d\n", (*listb)->index);
		(*listb) = (*listb)->next;
	}
*/	
	stack_size_b = list_size(*listb);
//	printf("numbero %d, indice %d\n", (*listb)->data, (*listb)->index);
//	printf("numbero %d, indice %d\n", (*listb)->next->data, (*listb)->next->index);
//	print_index(*listb);//
	while(stack_size_b > 0)	 
	{
		sort_chunked(lista, listb); 
		stack_size_b--;
	}
/*	while(*lista)
	{
		printf("index = %d\n", (*lista)->index);
		(*lista) = (*lista)->next;
	}*/
}	
/*
	stack_size_b = list_size(*listb);
	printf("paramsum b = %d\n", stack_size_b); //

	t_list *tmp;
	tmp = (*listb);

	while(*listb)
	{	
		get_target_position(lista, listb);
		get_cost(lista, listb);
		do_cheapest_move(lista, listb);
	}
	if(is_sorted(*lista) == false)
		shift_stack(lista);
}
*/
//------------------------------------------------------------------

void	how_to_sort(t_list **lista, t_list **listb, int stack_size)
{
	if(stack_size == 2 && is_sorted(*lista) == false)
		run_swap_a(lista);
	else if(stack_size == 3 && is_sorted(*lista) == false)
		sort_3(lista);
	else if(stack_size > 3 && is_sorted(*lista) == false)
		sort_all(lista, listb);
}
//function to sort 2, 3 and more numbers
//dispatch to other functions regarding the number of arguments
//--------------------------------------------------

