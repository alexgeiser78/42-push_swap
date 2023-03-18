/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:40:36 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/18 15:45:55 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//----------------------------------------------

t_list	*get_last(t_list *lst)
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
//--------------------------------------------------
