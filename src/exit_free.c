/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:25:14 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/08 16:50:18 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//--------------------------------------------------

void	exit_error(t_list **lista, t_list **listb)
{
	if (lista == NULL || *listb != NULL)
		free_list(lista);
	if (listb == NULL || *listb != NULL)
		free_list(listb);
	write(2, "Error\n", 6);
	exit (1);
}
//fonction of free mallocs and exit in case of error
//line 19 if the element of list a is Null and the list isn't empty,
//we free list a
//line 21 same for list b
//line 23 2 because it's the error output
//line 24 exit is a function that clean the I/O used by the program

//-----------------------------------------------

void	free_list(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

//function to free the malloc
//frees the mallocs of every elements of the list
//---------------------------------------------------

t_list	*free_at(t_list **lst, int pos)
{
	t_list	*last;
	t_list	*cur;
	int		i;

	last = *lst;
	cur = *lst;
	i = 0;
	if (!lst || !(*lst))
		return (NULL);
	if (pos == 0)
	{
		*lst = (*lst)->next;
		free(cur);
		return (*lst);
	}
	while (i < pos)
	{
	i++;
	last = cur;
	cur = cur->next;
	}
	last->next = cur->next;
	free(cur);
	return (*lst);
}
//function to free only  one element
//----------------------------------------------

t_Bool	overflow_suite(int i, char **str, int n)
{
	char	*check;

	check = ft_itoa(n);
		i = 1;
	while (str[i])
	{
		if (check != NULL)
			free(check);
		n = ft_atoi(str[i]);
		check = ft_itoa(n);
		if (ft_strncmp(str[i], check, ft_strlen(str[i])) != 0)
			return (false);
		i++;
	}
	if (check != NULL)
		free(check);
	return (true);
}
//line 96 check that during the convertion atoi ->itoa the number isn't
//modified to be accepted
