/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notte.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:34:25 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/23 15:16:35 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	do_cheapest_move(t_list **lista, t_list **listb)
{
	t_list *tmp;
	int	cheapest;
	int	cost_a;
	int	cost_b;

	tmp = *listb;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
	{
		cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
		cost_a = tmp->cost_a;
		cost_b = tmp->cost_b;
	}
		tmp = tmp->next;
	}
	do_move(lista, listb, cost_a, cost_b);
}
/*
void	get_cost(t_list **lista, t_list **listb)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int	size_a;
	int	size_b;

	tmp_a = *lista;
	tmp_b = *listb;
	size_a = list_size(*lista);
	size_b = list_size(*listb);
	while(tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
	       if (tmp_b->target_pos > size_a / 2)
	       		tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
  }
}	
*/
/*
int	get_target(t_list **lista, int listb_index, int target_index, int target_position)
{
	t_list *tmp;

	tmp = *lista;
	while(tmp)
	{
		if(tmp->index > listb_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_position = tmp->pos;
		}
		tmp= tmp->next;
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
}*/
/*
void	get_target_position(t_list **lista, t_list **listb)
{
	t_list *tmp;
	int	target_position;

	tmp = *listb;
	get_position(lista);
	get_position(listb);
	target_position = 0;
	while(tmp)
	{
		target_position = get_target(lista, tmp->index, INT_MAX, target_position);
		tmp->target_pos = target_position;
		tmp = tmp->next;
	}
}
*/
