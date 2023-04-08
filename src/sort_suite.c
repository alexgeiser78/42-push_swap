/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:51:24 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/24 18:08:09 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//----------------------------------------------------------

void	chunker(t_list **lista, t_list **listb, int i, int chunk_is)
{
	int	medium;
	int	stack_size_a;

	stack_size_a = list_size(*lista);
	medium = search_middle(lista);
	while (i <= stack_size_a)
	{	
		chunk_move(lista, listb, chunk_is, medium);
		i++;
	}
}
//function to put in listb what is smaller than the mid number of the lista
//every time we passed all lista, the number of the chunk increase,
//creating increasing blocks of unsorted numbers 
//[4]                 
//[3]       
//[2]   ->  [2]     ->    [2] chunk2
//[1]       [1][3]     [1][3] chunk1
//[0][]     [0][4]     [0][4] chunk1
//
//-----------------------------------------------------------

void	sort_list_a(t_list **lista, int stack_size_a)
{
	if (stack_size_a == 2 && (*lista)->data > (*lista)->next->data)
		run_swap_a(lista);
}
// function that swaps the 2 last numbers if there is 2 and
// if the highest is on top
//-----------------------------------------------------------------

void	sort_list_b(t_list **lista, t_list **listb)
{
	int	stack_size_b;

	stack_size_b = list_size(*listb);
	while (stack_size_b > 0)
	{
		sort_chunked(lista, listb);
		stack_size_b--;
	}
}
//main function to sort a big stack
//line 62 the function works till listb is empty
//line 64 we send everything to the sort_chunked function
//line 65 every time a number is pushed to lista we
//decrease the size of listb  
//----------------------------------------------------------------------

void	sort_chunked(t_list **lista, t_list **listb)
{
	int	h_i_p;
	int	stack_size_b;

	h_i_p = search_highest_index_position(listb);
	while (h_i_p != 0)
	{
		stack_size_b = list_size(*listb);
		if (h_i_p > stack_size_b / 2)
			run_rev_rot_b(listb);
		else
			run_rot_b(listb);
		h_i_p = search_highest_index_position(listb);
	}
	pa(lista, listb);
}

//--------------------------------------------------------------

int	search_highest_index_position(t_list **lst)
{
	t_list	*tmp;
	int		highest_index;
	int		position;

	tmp = (*lst);
	highest_index = INT_MIN;
	put_position(lst);
	position = tmp->pos;
	while (tmp)
	{
		if (tmp->index > highest_index)
		{
			highest_index = tmp->index;
			position = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (position);
}
//ligne 40 INT_MIN pour etre sur que le chiffre soit plus petit que
//l'index du premier element
//--------------------------------------------------------
