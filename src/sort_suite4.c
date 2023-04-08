/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_suite4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:00:50 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/24 18:12:57 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_move(t_list **lista, t_list **listb, int chunk_is, int medium)
{
	int	stack_size_a;

	stack_size_a = list_size(*lista);
	if ((*lista)->data < medium)
	{
		if ((*lista)->data < medium / 2)
		{
			(*lista)->chunk = chunk_is;
			pb(lista, listb);
			run_rot_b(listb);
		}
		else
		{
			(*lista)->chunk = chunk_is;
			pb(lista, listb);
		}
	}
	else
		run_rot_a(lista);
}
