/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_suite2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:14:42 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/24 17:08:43 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-----------------------------------------------
/*
int	get_target(t_list **lista, int listb_index, int target_index, 
int target_position)
{
	t_list *tmp;

	tmp = *lista;
	while(tmp)
	{
		if (tmp->index > listb_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_position = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return(target_position);
	tmp = *lista;
	while(tmp)
	{
		if (tmp->index < target_index)
		{
		target_index = tmp->index;		
		target_position = tmp->pos;
		}
		tmp = tmp->next;
	}
	return(target_position);
}

//------------------------------------------------
void	put_target_position(t_list **lista, t_list **listb)
{
	t_list *tmp;
	int	target_position;

	tmp = *listb;
	put_position(lista);
	put_position(listb);
	target_position = 0;
	while(tmp)
	{
		target_position = get_target(lista, tmp->index, INT_MAX, target_position);
		tmp->target_pos = target_position;
		tmp = tmp->next;
	}
}
//---------------------------------------------------

void	put_cost(t_list **lista, t_list **listb)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int size_a;
	int size_b;

	tmp_a = *lista;
	tmp_b = *listb;
	size_a = list_size(*lista);
	size_b = list_size(*listb);
	while(tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b /2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
				tmp_b = tmp_b->next;
	}
}

//-----------------------------------------------------

void	do_cheapest_move(t_list **lista, t_list **listb)
{
	t_list *tmp;
	int cheapest;
	int cost_a;
	int cost_b;

	tmp = *listb;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = tmp->cost_b + tmp->cost_a;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(lista, listb, cost_a, cost_b);
}

//----------------------------------------------------------

void	do_move(t_list **lista, t_list **listb, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(lista, listb, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b >0)
		do_rotate_both(lista, listb, &cost_a, &cost_b);
	do_rotate_a(lista, &cost_a);
	do_rotate_b(listb, &cost_b);
	pa(lista, listb);
}

//------------------------------------------------------------

int	nb_abs(int nb)
{
	if (nb < 0)
		return(nb * -1);
	return(nb);
}*/
