/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:12:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/11 17:10:57 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
		  
int main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	int num = 0;
	int paramsum = argc -1;
	int sizea = 0;
	int sizeb = 0;
	
	if(argc < 2)
	{
		write(2, "Error\n", 6);
		return(0);
	}
//	else
//		error_checker(argv[1]);



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
	i = 0; j = 1;

	while(i < paramsum)
	{
	num = ft_atoi(argv[j]);
	listb = add_at(listb, num, i);
	i++;
	j++;	
	}
	

	printf("\n");//printf
	printf("///////include numbers/////////\n");

	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n");	//printf
	print_list(listb);
	printf("B\n"); //printf
	printf("\n");
/*
	printf("////////sa///////////\n");//printf
	lista = sa(lista);

	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf	
	print_list(listb);
	printf("B\n");
	printf("\n");

	printf("///////sb////////////\n");//printf
	listb = sb(listb);

	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");

	printf("///////ss//////////////\n"); //printf
	ss(lista, listb);

	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");

//	sizea = list_size(lista);
//	sizeb = list_size(listb);

	printf("/////////free a///////////\n");
	lista = new_list();
	
	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");
*/
/*
	printf("/////// pa 3x ///////////////\n");
	pa(&lista, &listb);
	pa(&lista, &listb);
	pa(&lista, &listb);
// le & permet de modifier l-espace memoire alloue
	printf("5\n");
	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");

	printf("/////// pb 3x ///////////////\n");
	pb(&lista, &listb);
	pb(&lista, &listb);
	pb(&lista, &listb);
// le & permet de modifier l-espace memoire alloue
	printf("5\n");
	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");
*/
/*	
	printf("///////////ra & rb///////////\n\n");
	ra(&lista);
	rb(&listb);

	printf("///////////rr///////////////\n\n");
	rr(&lista, &listb);
*/
/*
	printf("///////////rra & rrb/////////////\n\n");
	rra(&lista);
	rrb(&listb);

	printf("output\n");
	print_list(lista);
	printf("A\n");//printf
	printf("------------------\n"); //printf
	print_list(listb);
	printf("B\n");
	printf("\n");
*/
	printf("//////////rrr/////////");
	rrr(&lista, &listb);	

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
*/
