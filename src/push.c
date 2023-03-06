/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:17:19 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/06 14:59:56 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa(t_list **lista, t_list **listb)
{
	t_list	*tmp;

	if (*listb == NULL)
		return ;
	tmp = (*listb)->next;
	(*listb)->next = *lista;
	*lista = *listb;
	*listb = tmp;
	write(1, "pa\n", 3);
	return ;
}
//on stocke dans tmp le deuxieme element de la liste b, qui 
//a la fin sera le premier
//le premier element de la liste b pointe sur la liste a
//on copie la liste b dans la liste a
//dans la liste b on remet le deuxieme element qui etait en tampon
//
//     init        ligne 61       ligne 62       ligne 63 
//        12       
//        24                                           24 
//        36  ->         12  ->   12    12  ->   12    36
// null null      null  null     null  null     nul   null
//  A    B         A     B        A     B        A      B

//-------------------------------------------

void	pb(t_list **lista, t_list **listb)
{
	t_list	*tmp;

	if (*lista == NULL)
		return ;
	tmp = (*lista)->next;
	(*lista)->next = *listb;
	*listb = *lista;
	*lista = tmp;
	write(1, "pb\n", 3);
	return ;
}
