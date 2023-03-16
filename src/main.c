/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:12:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/16 17:33:02 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	int	stack_size;
	t_list *lista;
	t_list *listb;
	
	if(argc < 2)
		return(0);
	if(input_check(argv) == false || overflow_checker(argv) == false)
		exit_error(NULL, NULL); // (NULL, NULL) permet d'etre sure que les malloc seront free

//----------create lists	
	listb = new_empty_list();
	lista = list_maker(argc, argv);

//----------input
	printf("\n");//printf
	printf("input\n");//printf

	print_list(lista);//printf
	printf("A\n");//printf
	printf("------------------\n");	//printf
	print_list(listb);//printf
	printf("B\n"); //printf
	printf("\n");//printf

//---------list_size
	stack_size = list_size(lista);
//	printf("stack_size = %d\n", stack_size); //printf

//--------list_index	
	put_index(lista, stack_size); //(+1)

//--------sort
	how_to_sort(&lista, &listb, stack_size);

//output
	printf("output\n");//printf
	print_list(lista);//printf
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);//printf
	printf("B\n");//printf
	printf("\n");//printf
	
//	free(lista);
//	free(listb);
}

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
