/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:39:09 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/17 17:34:50 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-----------------------------------------------------

t_list	*new_empty_list(void)
{
	return (NULL);
}

//-----------------------------------------------------

t_list	*list_maker(int argc, char **argv)
{
	t_list		*lista;
	long int	num;
	int			i;

	lista = new_empty_list();
	num = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error(&lista, NULL);
		if (i == 1)
			lista = create_element(num, 0);
		else
			lista = add_at(lista, num, i -1, 0);
		i++;
	}
	return (lista);
}
// ligne 30 we create an empty list
// ligne 32 i = nbr of argument
// ligne 36 if data is higher or lower than the min or 
// max possible, we exit the prgm
//ligne 38 if i = 1 whiche is the case in the first loop, we
//create the element we all its value. data, index...
//ligne 40 we add the data and reset all values  
//---------------------------

t_list	*create_element(int data, int index)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->data = data;
	element->index = index;
	element->chunk = 0;
	element->pos = -1;
	element->cost = INT_MAX;
	element->next = NULL;
	return (element);
}
//ligne 55, we need the index because this function is 
//gonna be used during the sort
//ligne 59 malloc with all values contained in t_list
//ligne 65 -1 because 0 could be a position
//ligne 66 INT_MAX to be sure
//ligne 67 pointer to next
//-------------------------------------------------------

t_list	*add_at(t_list *lst, int data, int pos, int index)
{
	t_list		*last;
	t_list		*cur;
	t_list		*element;
	int			i;

	i = 0;
	last = lst;
	cur = lst;
	element = create_element(data, index);
	if (is_empty_list(&lst))
		return (element);
	if (pos == 0)
	{
		element->next = lst;
		return (element);
	}
	while (i < pos)
	{
	i++;
	last = cur;
	cur = cur->next;
	}
	last->next = element;
	element->next = cur;
	return (lst);
}
//function to add at a certain position
//ligne 81 et 82 pointer to save the last and current pointer to next
//ligne 88 we create a new element
//ligne 89 if the list is empty, than we return only this element
//which will be the list when returning to the previous function
//ligne 91 if the position searched is 0 (first) we return
// the element which will be the list when returning to the
// previous function
// ligne 96 we search for the required position, swapping last and cur
// to not loose our ->next link
