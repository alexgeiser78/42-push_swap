/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:20:34 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/14 17:33:30 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_list **lst)
{
	int	swap;
	int	last;

	swap = (*lst)->data;
	last = list_size(*lst);
	add_at(*lst, swap, last);
	free_at(lst, 0);
	write(1, "ra\n", 3);
}
// ligne 102 on stocke dans swap la data du premier element
// ligne 103 on compte le nombre d'element de la chaine que 
// l'on stocke dans last
// ligne 104 a la position swap on ajoute l'element final avec la valeur de swap
// ligne 105 on libere le premier element de la chaine
//------------------------------------------------

void	rb(t_list **lst)
{
	int	swap;
	int	last;

	swap = (*lst)->data;
	last = list_size(*lst);
	add_at(*lst, swap, last);
	free_at(lst, 0);
	write(1, "rb\n", 3);
}

//-------------------------------------------------

void	rr(t_list **lista, t_list **listb)
{
	ra(lista);
	rb(listb);
	write(1, "rr\n", 3);
}
