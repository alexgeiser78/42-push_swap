/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:59:26 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/14 17:32:18 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*sa(t_list *lst)
{
	int	swap;

	if (lst == NULL || lst->next == NULL)
		return (0);
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
	write(1, "sa\n", 3);
	return (lst);
}
/* on stocke dans swap le data du premier element, le data du permier element 
prend le data du deuxieme element, le deuxieme element prend le data de swap 
soit premier element */

//-----------------------------------------------------------------

t_list	*sb(t_list *lst)
{
	int	swap;

	if (lst == NULL || lst->next == NULL)
		return (0);
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
	write(1, "sb\n", 3);
	return (lst);
}

//-----------------------------------------------------------------

void	*ss(t_list *lista, t_list *listb)
{
	lista = sa(lista);
	listb = sb(listb);
	write(1, "ss\n", 3);
	return (0);
}
