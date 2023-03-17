/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/17 18:25:02 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-------------------------------------------------------

void	print_list(t_list *lst)
{
	if (is_empty_list(&lst))
	{
		printf ("empty list\n"); //printf
		return ;
	}
	while (lst)
	{
		printf ("[%d]\n", lst->data); //printf
		lst = lst->next;
	}
	printf ("[NULL]\n");//printf
}

//------------------------------------------------------

void	print_index(t_list *lst)
{
	t_list *tmp;
	tmp = lst;

	while (tmp)
	{
		printf("index = %d\n", tmp->index);//printf
		tmp = tmp->next;
	}
	printf("[NULL]\n");//printf
}

//-------------------------------------------------------

int	get_at(t_list *lst, int pos)
{
	int	i;

	i = 0;
	if (is_empty_list(&lst))
	{
		printf ("liste vide\n"); //printf
		return (-1);
	}
	while (i < pos)
	{
		i++;
		lst = lst->next;
	}
	return (lst->data);
}

//-----------------------------------------------

void	set_at(t_list *lst, int data, int pos)
{
	int	i;

	i = 0;
	if (is_empty_list(&lst))
	{
		printf ("liste vide\n"); //printf
		return ;
	}
	while (i < pos)
	{
		i++;
		lst = lst->next;
	}
	lst->data = data;
}

//-----------------------------------------

t_list	*free_at(t_list **lst, int pos)
{
	int	i;
	t_list	*last;
	t_list	*cur;

	last = *lst;
	cur = *lst;
	i = 0;
	if (is_empty_list(lst))
		return (NULL);
	if (pos == 0)
	{
		*lst = (*lst)->next;
		free(cur);
		return (*lst);
	}
	while (i < pos)
	{
	i++;
	last = cur;
	cur = cur->next;
	}
	last->next = cur->next;
	free(cur);
	return (*lst);
}

//-----------------------------------------------

t_list	*free_list(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (lst)
	{
	tmp = lst->next;
		printf("del [%d]\n", lst->data); //printf
		free (lst);
	lst = tmp;
	}
	return (lst);
}

//----------------------------------------------

t_list	*get_last(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// find last element
//--------------------------------------------------

t_list	*get_penultieme(t_list *lst)
{
	while (lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
//find before-last element
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
//--------------------------------------------------

int	arg_counter(t_list *lst)
{
	int size;

	size = 0;
	if (!lst)
		return(0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return(size);
}
//argument counter
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

//function to sort 3 numbers using the less steps possible
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
//----------------------------------------------------------------------
/*
int	search_high(t_list **lst, int block)
{
	t_list *tmp;
	int max;
	tmp = (*lst);
	max = (*lst)->data;
	
	printf("init search_hign data = %d\n", (*lst)->data);
	printf("init search_high block= %d\n", (*lst)->chunk);
	
	while((*lst)->chunk == block)
	{
		printf("data %d\n",(*lst)->data);
		printf("block %d\n", (*lst)->chunk);
		printf("chunk = %d\n", block);
		
		if((*lst)->data >= max)
		{
			max = (*lst)->data;
			printf("bigger\n");
		}
		if((*lst)->next != NULL)
			(*lst) = (*lst)->next;
	 //      	printf("no bigger\n");	
		else
			break;//
	}
	printf("max = %d\n", max);
	*lst = tmp;
	return(max);
}	
*/



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

void	how_to_sort(t_list **lista, t_list **listb, int paramsum)
{
	if(paramsum == 2 && is_sorted(*lista) == false)
		run_swap_a(lista);
	else if(paramsum == 3 && is_sorted(*lista) == false)
		sort_3(lista);
	else if(paramsum > 3 && is_sorted(*lista) == false)
		sort_all(lista, listb);
}
//function to sort 2, 3 and more numbers
//--------------------------------------------------

void	exit_error(t_list **lista, t_list **listb)
{
	if (lista == NULL || *listb != NULL)
		free_list(*lista);
	if (listb == NULL || *listb != NULL)
		free_list(*listb);
	write(2, "Error\n", 6);
	exit (1);
}
//fonction de free des malloc et sortie = pour cause d'erreur
//ligne 105 si l'element de la liste a est null et la liste a n'est pas vide, 
//on free la liste a
//ligne 107 pareil pour la liste b
//ligne 109 2 parce que c'est la sortie d'erreur
//ligne 110 exit est un fonction qui fait une routine de nettoyage des 
//E/S utilises lors de l'execution du programme

