/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:22:37 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/14 18:24:15 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *get_last(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// find last element
//--------------------------------------------------

t_list	*get_penultieme(t_list *lst)
{
	while (lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
//find before-last element
//-------------------------------------------------

void	rra(t_list **lst)
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
	write(1, "rra\n", 4);
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

void	rrb(t_list **lst)
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
	write(1, "rrb\n", 4);
}

//-------------------------------------------------

void	rrr(t_list **lista, t_list **listb)
{
	rra(lista);
	rrb(listb);
	write(1, "rrr\n", 4);
}
