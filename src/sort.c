/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/23 15:45:34 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//--------------------------------------------------

int	is_bigger(t_list *lista)
{
	int	big;

	big = lista->data;
	while (lista)
	{
		if (lista->data > big)
			big = lista->data;
		lista = lista->next;
	}
	return (big);
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

//function to sort 3 numbers using the less steps possible
//line 39 we search for the biggest number
//line 40 if the biggest number is on top we put it on the base
//line 42 if the second number is the biggest we put the base on top
//line 44 if the first number is higher than the second we swap 
//the two first
//
//[3]      [2]     [1]     [2]     [1]     [1]     [2]    [1]
//[2]  ra  [1] sa  [2]     [3] rra [2]     [3] rra [1] sa [2]
//[1]  ->  [3] ->  [3]     [1]	-> [3]	   [2]	-> [3] -> [3]
//
//[2]    [1]   [3]    [1]  
//[1] sa [2]   [1] ra [2]
//[3] -> [3]   [2] -> [3] 
//--------------------------------------------------

int	search_middle(t_list **lst)
{
	int		add;
	int		i;
	int		med;
	t_list	*tmp;

	i = 1;
	med = 0;
	tmp = (*lst);
	add = (*lst)->data;
	while ((*lst)->next)
	{	
		(*lst) = (*lst)->next;
		add = add + (*lst)->data;
		i++;
	}
		*lst = tmp;
	med = add / i;
	return (med);
}

//function to find the mid number in the list,
//we add all number that we divide by the number of arguments 
//--------------------------------------------------------------------

void	sort_all(t_list **lista, t_list **listb)
{
	int	i;
	int	stack_size_a;
	int	chunk_is;
	i = 0;
	chunk_is = 1;
	stack_size_a = list_size(*lista);
	while (stack_size_a > 3)//
	{
		chunker(lista, listb, i, chunk_is);
		chunk_is++;
		i = 0;
		stack_size_a = list_size(*lista);
	}
	if (stack_size_a == 3)
		sort_3(lista);
	sort_list_a(lista, stack_size_a);
	sort_list_b(lista, listb);
}
//function of redirection to chunker which put in listb using chunk package
//than sort the lista and  main sort of listb
//line 96 i decide that the chunks(blocks) gonna start with 1 instead of 0
//line 98 i want that stays in lista not more than 2 numbers
//line 100 is a function with a lot of argument and the result of 
//cutting my function because has more than 25 lines(shit rule)
//line 103 always mesure the list size every time an element is 
//pushed to b or not   
//------------------------------------------------------------------

void	how_to_sort(t_list **lista, t_list **listb, int stack_size)
{
	if (stack_size == 2 && is_sorted(*lista) == false)
		run_swap_a(lista);
	else if (stack_size == 3 && is_sorted(*lista) == false)
		sort_3(lista);
	else if (stack_size > 3 && is_sorted(*lista) == false)
		sort_all(lista, listb);
}
//function to sort 2, 3 and more numbers
//dispatch to other functions regarding the number of arguments
//--------------------------------------------------
