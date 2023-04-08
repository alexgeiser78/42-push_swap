/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:12:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/24 19:09:03 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (input_check(argv) == false || overflow_checker(argv) == false)
		exit_error(NULL, NULL);
	listb = new_empty_list();
	lista = list_maker(argc, argv);
	stack_size = list_size(lista);
	put_index(lista, stack_size);
	how_to_sort(&lista, &listb, stack_size);
	free_list(&lista);
	free_list(&listb);
	return (0);
}

//line 23 check error
//line 24 (NULL, NULL) to force the malloc to free
//line 25 create an empty list on stack b
//line 26 put all args in stack a
//line 27 stacksize of stack a usefull in other operations
//line 28 put index, the highest the biggest
//line 29 main sort function

//---------------------------------------------------
