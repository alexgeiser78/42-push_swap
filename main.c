/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/17 14:06:44 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h> //printf
#include"push_swap.h"
#include<stdlib.h>//malloc

t_list *new_list(void)
{
	return(NULL);
}

/*-----------------------------------------------------*/

Bool is_empty_list(t_list *lst)
{
	if(lst == NULL)
		return(true);
	return(false);
}

/*------------------------------------------------------*/

int list_size(t_list *lst)

{
	int size = 0;

	if(is_empty_list(lst))
		return(size);

	while(lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return(size);
}

/*-------------------------------------------------------*/

void print_list(t_list *lst)
{
if(is_empty_list(lst))
{ 
	printf("empty list\n");
	return;
}
	while(!is_empty_list(lst))
{
	printf("[%d]\n", lst->data);
	lst = lst->next;
}
printf("NULL\n");
}
/*-------------------------------------------------------*/

//static
t_list *create_element(int data)
{
	t_list *element = malloc(sizeof(t_list));
	if(!element)
		return(NULL);
	element->data = data;
	element->next = NULL;

	return(element);
}

/*-------------------------------------------------------*/

t_list *add_at(t_list *lst, int data, int pos)
{
	t_list *last = lst;
	t_list *cur = lst;
	int i = 0;
	t_list *element = create_element(data);
	if(is_empty_list(lst))
		return(element);
	if(pos == 0)
	{
		element->next = lst;
		return(element);
	}
	while(i < pos)
	{
	i++;
	last = cur;
	cur = cur->next;
	}
	last->next = element;
	element->next = cur;

	return(lst);	
}

/*-------------------------------------------------------*/

/*
t_list push_back_list(t_list lst, int x)
{
	t_list *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		printf("malloc error");
		exit(EXIT_FAILURE);
	}	

	element->data = x;
	element->next = NULL;

	if(is_empty_list(lst))
		return element;

	t_list *temp;
	temp = lst;
	
	while(temp->next != NULL)
		temp = temp->next;

	temp->next = element;

	return (lst);

}

//---------------------------------------------------------------
*/

t_list push_front_list(t_list *lst, int x)
{
	t_list *element;

	element = malloc(sizeof(*element));

	element->data = x;

	if(is_empty_list(lst))
		element->next = NULL;
	else
		element->next= lst;
	return *element;
}	

//-----------------------------------------------------------------
/*
t_list pop_back_list(t_list lst)

{
	if(is_empty_list(lst))
		return new_list();

	if(lst->next == NULL)
	{
		free(lst);
		lst = NULL;
		return new_list();
	}
	t_list *temp = lst;
	t_list *before = lst;

	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;
	free(temp);
	temp = NULL;

	return lst;
}

//---------------------------------------------------------

t_list pop_front_list(t_list lst)
{
	if(is_empty_list(lst))
		return(lst);
	
	t_list *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}

	element = lst->element;

	free(lst);
	lst = NULL;
		
	return(element);
}
*/
//-----------------------------------------------

t_list *free_list(t_list *lst)
{
	t_list *tmp = NULL;
	while(lst)
	{
	tmp = lst->next;
	printf("del [%d]\n", lst->data); //printf
	free(lst);
	lst = tmp;
	}
return(lst);
}	

int main(void)
{
//	if(argc < 2)
//		return(0);
//	else
//	{
		t_list *lista = new_list();
		
		if(is_empty_list(lista))
			printf("lista is empty!\n");   //printf
		else
			printf("lista contains element\n");   //printf
		print_list(lista);
		printf("list size = %d\n", list_size(lista));
		
		lista = add_at(lista, 36, 0);
		lista = add_at(lista, 48, 0);
		lista = add_at(lista, 60, 1);
		print_list(lista);	
		printf("list size = %d\n", list_size(lista)); //printf
		free_list(lista);

}	

