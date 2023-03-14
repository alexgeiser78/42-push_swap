/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notte2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:50:43 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/14 13:52:12 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_abs(int nb)
{
	if (nb < 0)
		return(nb * -1);
	return(nb);
}

void	do_rev_rotate_both(t_list **lista, t_list **listb, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		run_rev_rot_ab(lista, listb);
	}
}

void	do_rotate_both(t_list **lista, t_list **listb, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		run_rot_ab(lista, listb);
	}
}

void	do_rotate_a(t_list **lista, int *cost)
{
	while(*cost)
	{
		if(*cost > 0)
		{
			run_rot_a(lista);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			run_rev_rot_a(lista);
			(*cost)++;
		}
	}
}

void	do_rotate_b(t_list **listb, int *cost)
{
	while(*cost)
	{
		if (*cost > 0)
		{
			run_rot_b(listb);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			run_rev_rot_b(listb);
			(*cost)++;
		}
	}
}

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
