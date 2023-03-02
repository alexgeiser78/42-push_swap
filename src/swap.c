/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:59:26 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/15 15:21:06 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_list *lst)
{
	int	swap;

	if (lst == NULL || lst->next == NULL)
		return ;
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
}
/* on stocke dans swap le data du premier element, le data du permier element 
prend le data du deuxieme element, le deuxieme element prend le data de swap 
soit premier element */

//--------------------------------------------------------

void	run_swap_a(t_list **lista)
{
	ft_swap(*lista);
	write(1, "sa\n", 3);
}

//-------------------------------------------------------
void	run_swap_b(t_list **listb)
{
	ft_swap(*listb);
	write(1, "sb\n", 3);
}

//------------------------------------------------------

void	run_swap_ab(t_list *lista, t_list *listb)
{
	ft_swap(lista);
	ft_swap(listb);
	write(1, "ss\n", 3);
}
