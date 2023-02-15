/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:12:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/15 17:50:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
		  
int main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	int num = 0;
	int paramsum = argc -1;
//	int sizea = 0;
//	int sizeb = 0;
	
	if(argc < 2)
	{
		write(2, "Error\n", 6);
		return(0);
	}
	if(!input_true(argv))
	{
		write(2, "Error\n", 6);
		return(0);
	}


//----------create lists	
	t_list *lista = new_list();
	t_list *listb = new_list();
	
//----------putnbr A
	while(i < paramsum)
	{
	num = ft_atoi(argv[j]);
	lista = add_at(lista, num, i);
	i++;
	j++;	
	}

//-----------putnbr B
/*	i = 0; j = 1;

	while(i < paramsum)
	{
	num = ft_atoi(argv[j]);
	listb = add_at(listb, num, i);
	i++;
	j++;	
	}
*/	

	printf("\n");//printf
	printf("///////include numbers/////////\n");

	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n");	//printf
	print_list(listb);
	printf("B\n"); //printf
	printf("\n");


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

	printf("output\n");
	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");
	
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
*/
