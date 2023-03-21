/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbidden.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:33:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/21 18:07:44 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-------------------------------------------------------

void	print_list(t_list *lst)
{
	if (is_empty_list(&lst))
	{
		printf ("empty list\n");
		return ;
	}
	while (lst)
	{
		printf ("[%d]\n", lst->data);
		lst = lst->next;
	}
	printf ("[NULL]\n");
}
//function that prints all data
//------------------------------------------------------

void	print_index(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("index = %d\n", tmp->index);
		tmp = tmp->next;
	}
	printf("[NULL]\n");
}
//function that prints all index
//-------------------------------------------------------

int	get_at(t_list *lst, int pos)
{
	int	i;

	i = 0;
	if (is_empty_list(&lst))
	{
		printf ("liste vide\n"); //printf
		return (-1);
	}
	while (i < pos)
	{
		i++;
		lst = lst->next;
	}
	return (lst->data);
}
//function that prints the data of a prticular element
//-----------------------------------------------

void	set_at(t_list *lst, int data, int pos)
{
	int	i;

	i = 0;
	if (is_empty_list(&lst))
	{
		printf("empty list\n");
		return ;
	}
	while (i < pos)
	{
		i++;
		lst = lst->next;
	}
	lst->data = data;
}
