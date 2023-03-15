/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:07:14 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/15 13:41:26 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
/*
t_list *new_list(int data)
{
	t_list *new;

	new = malloc(sizeof * new);//?
	if (!new)
		return(NULL);
	new->data = data;
	new->index = 0;
	new->chunk = 0;
	new->pos = -1; //?
	new->cost_a = -1;//?
	new->cost_b = -1;//?
	new->next = NULL;
	return (new);
}
*/
	


int	nbrlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
	i++;
	}
	return (i);
}

t_list	*list_maker(int argc,  char **argv)
{
	t_list		*lista;
	long int	num;
	int		i;

	lista = new_empty_list();
	num = 0;
	i = 1;
	while(i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error(&lista, NULL);
		if (i == 1)
			lista = create_element(num); 
		else
			lista = add_at(lista, num, i -1);
		i++;
	}
	return (lista);
}


