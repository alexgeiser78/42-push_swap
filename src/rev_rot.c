/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:22:37 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/15 16:12:15 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rev_rot(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*penultieme;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
		last = get_last(*lst);
		penultieme = get_penultieme(*lst);
		tmp = *lst;
		*lst = last;
		(*lst)->next = tmp;
		penultieme->next = NULL;
}
//ligne 169 on stocke le dernier element dans last
//ligne 170 on stocke l'avant dernier element dans penultieme
//ligne 171 on stocke le pointeur de debut de chaine dans tmp
//ligne 172 le pointeur de debut de chaine pointe sur le dernier element
//ligne 173 l'element suivant ce pointeur == pointeur de debut de chaine. 
//La chaine n'est pas fermee d'ou creation d'une boucle infinie a ce stade
//ligne 174 l'vant dernier element est relie a la fin de chaine
//    init       ligne  172    ligne 173    ligne 174
//     12                         36         36
//     24                         12         12 
//     36  ->        36   ->      24   ->    24
//    null          null         ...        null
//      A            A           ...          A

//-------------------------------------------------

void	run_rev_rot_a(t_list **lista)
{
	ft_rev_rot(lista);
	write(1, "rra\n", 4);
}

//-------------------------------------------------

void	run_rev_rot_b(t_list **listb)
{
	ft_rev_rot(listb);
	write(1, "rrb\n", 4);
}

//-------------------------------------------------

void	run_rev_rot_ab(t_list **lista, t_list **listb)
{
	ft_rev_rot(lista);
	ft_rev_rot(listb);
	write(1, "rrr\n", 4);
}
