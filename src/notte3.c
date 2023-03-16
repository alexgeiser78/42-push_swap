/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notte3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:31:42 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/16 15:01:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	shift_stack(t_list **lista)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = list_size(*lista);
	lowest_pos = get_lowest_index_position(lista);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
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
}

