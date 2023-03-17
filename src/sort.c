/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:51:24 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/17 13:10:39 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	put_position(t_list **lst)
{
	t_list	*tmp;
	int	i;

	tmp = (*lst);
	i = 0;
	while(tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
//attribue une position dans la liste, du plus petit au sommet au plus grand a la base


int	search_highest_index_position(t_list **lst)
{
	t_list *tmp;
	int	highest_index;
	int	position;

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
//	printf("highest_index_position = %d\n", position);//
	return(position);
}
//ligne 40 INT_MIN pour etre sur que le chiffre soit plus petit que
//l'index du premier element


void	sort_chunked(t_list **lista, t_list **listb)
{
	int	h_i_p;
//	h_i_p = INT_MAX;
//	int stack_size_b;
//	stack_size_b = list_size(*listb); 
//	put_index(*listb, stack_size_b);
	h_i_p = search_highest_index_position(listb);	
	while(h_i_p != 0)
	{
//		h_i_p = INT_MAX;
//		printf("index = %d\n", (*listb)->index);//
		run_rev_rot_b(listb);
		h_i_p = search_highest_index_position(listb);	
	}
	pa(lista, listb);
}
