/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:11:06 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/24 17:40:08 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-------------------------------------------

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

//----------------------------------------------
/*
void	shift_stack(t_list **lista)
{
	int lowest_pos;
	int stack_size;
	stack_size = list_size(*lista);
	lowest_pos = search_highest_index_position(lista);
	if (lowest_pos > stack_size / 2)
	{
		while(lowest_pos < stack_size)
		{
			run_rev_rot_a(lista);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			run_rot_a(lista);
			lowest_pos--;
		}
	}
}*/

//---------------------------------------------------------

//----------------------------------------------------------
