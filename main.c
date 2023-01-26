/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:12:12 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/26 17:46:48 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>//printf
#include"push_swap.h"
#include<stdlib.h>//malloc
#include<unistd.h>//write
		  
int main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	int num = 0;
	int paramsum = argc -1;
/*	
	if(argc < 2)
	{
		write(2, "Error\n", 6);
		return(0);
	}
	else
		error_checker(argv[1]);
*/

	t_list *lista = new_list();
	t_list *listb = new_list();
	

	while(i < paramsum)
	{
	num = ft_atoi(argv[j]);
	lista = add_at(lista, num, i);
	i++;
	j++;	
	}

	print_list(lista);
	printf("------------------\n");	
	print_list(listb);

	free(lista);
	free(listb);
}

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
