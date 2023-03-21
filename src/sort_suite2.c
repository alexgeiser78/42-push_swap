/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_suite2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:14:42 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/21 18:09:43 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//------------------------------------------------
//
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
