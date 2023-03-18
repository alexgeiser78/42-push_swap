/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:12:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/18 13:43:04 by ageiser          ###   ########.fr       */
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
	printf("\n");//printf
	printf("input\n");//printf
	print_list(lista);//printf
	printf("A\n");//printf
	printf("------------------\n");//printf
	print_list(listb);//printf
	printf("B\n"); //printf
	printf("\n");//printf
	stack_size = list_size(lista);
	put_index(lista, stack_size);
	how_to_sort(&lista, &listb, stack_size);
	printf("output\n");//printf
	print_list(lista);//printf
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);//printf
	printf("B\n");//printf
	printf("\n");//printf	
//	print_index(lista);//
	free_list(&lista);
	free_list(&listb);
	return (0);
}

//ligne 24 (NULL, NULL) to force the malloc to free

//---------------------------------------------------

//list_learning
/*
  	if(is_empty_list(lista))
  		printf("lista is empty!\n"); //printf
	else
		printf("lista contains element\n"); //printf
		
	print_list(lista);
	printf("list size = %d\n");

	lista = add_at(lista, 36, 0);
	lista = add_at(lista, 48, 0);
	lista = add_at(lista, 60 , 1);
	print_list(lista);
	printf("list size = %d \n", list_size(lista)); //printf
	printf("data 1 = %d\n", get_at(lista, 1));//printf
	set_at(lista, 40 , 1);
	printf("data 1 = %d\n", get_at(lista, 1)); //printf
	print_list(lista);
	printf("del element 1\n");//printf
	free_at(lista, 1);
	print_list(lista);
	free_list(lista);
	sizea = list_size(lista);
	sizeb = list_size(listb);

//	run_swap_a(&lista);
//	run_swap_b(&listb);
//	run_swap_ab(lista, listb);

//	pa(&lista, &listb);
//	pb(&lista, &listb);

//	run_rot_a(&lista);
//	run_rot_b(&listb);
//	run_rot_ab(&lista, &listb);

//	run_rev_rot_a(&lista);
//	run_rev_rot_b(&listb);
//	run_rev_rot_ab(&lista, &listb);	








*/
