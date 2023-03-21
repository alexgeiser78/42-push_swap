/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:54:16 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/21 18:10:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-----------------------------------------------------

int	list_size(t_list *lst)

{
	int	size;

	size = 0;
	if (is_empty_list(&lst) == true)
		return (size);
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

//--------------------------------------------------

void	put_index(t_list *lst, int stack_size)
{
	t_list	*tmp;
	t_list	*highest;
	int		data_is;

	while (--stack_size > 0)
	{
		tmp = lst;
		data_is = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->data == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->data > data_is && tmp->index == 0)
			{
			data_is = tmp->data;
			highest = tmp;
			tmp = lst;
			}
			else
			tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
//line 41 list_a is filled now, so we put an index on each number
//the highest the number the highest the index
//line 43 as we modify the list we have to use tmp to recover
//the ->next link
//line 44 initialisation of the data
//line 45 initialisation of the pointer 
//line 48 in case of INT_MIN for the data, the index will be 1
//line 50 if the tmp->data is bigger than data_is, we put the index
//regarding to elevation of the number
//ligne 59 the highest element will be stored in *pointer so
//when we loop, this data will be the base 
//-------------------------------------------------------------

void	put_position(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = (*lst);
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
//attribue une position dans la liste, 
//du plus petit au sommet au plus grand a la base
//-----------------------------------------------------------------
