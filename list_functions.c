/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/30 15:23:25 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdlib.h>//malloc
#include<unistd.h>//write

//-----------------------------------------------------

t_list *new_list(void)
{
	return(NULL);
}

//-----------------------------------------------------

Bool is_empty_list(t_list *lst)
{
	if(lst == NULL)
		return(true);
	return(false);
}

//------------------------------------------------------

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

//-------------------------------------------------------

void print_list(t_list *lst)
{
if(is_empty_list(lst))
{ 
	printf("empty list\n"); //printf
	return;
}
//	while(!is_empty_list(lst))
	while(lst)
{
	printf("[%d]\n", lst->data); //printf
	lst = lst->next;
}
printf("[NULL]\n");
}

//-------------------------------------------------------

//static?
t_list *create_element(int data)
{
	t_list *element = malloc(sizeof(t_list));
	if(!element)
		return(NULL);
	element->data = data;
	element->next = NULL;

	return(element);
}

//-------------------------------------------------------

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

//-------------------------------------------------------

int get_at(t_list *lst, int pos)
{
	int i = 0;
	if(is_empty_list(lst))
	{
	printf("liste vide\n"); //printf
	return (-1);
	}
	while(i < pos)
	{
		i++;
		lst = lst->next;
	}
	return(lst->data);
}

//-----------------------------------------------

void set_at(t_list *lst, int data, int pos)
{
	int i = 0;
	if(is_empty_list(lst))
	{
	printf("liste vide\n"); //printf
	return;
	}
	while(i < pos)
	{
		i++;
		lst = lst->next;
	}
	lst->data = data;
}

//---------------------------------------------

/*
t_list push_back_list(t_list lst, int data)
{
	t_list *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		printf("malloc error");
		exit(EXIT_FAILURE);
	}	

	element->data = data;
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
*/
//---------------------------------------------------------------


t_list *push_front_list(t_list *lst, int data)
{
	t_list *element;

	element = create_element(data);

	element->data = data;

	if(is_empty_list(lst))
		element->next = NULL;
	else
		element->next= lst;
	return (lst);
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

//-----------------------------------------

t_list *free_at(t_list *lst, int pos)
{
	t_list *last = lst;
	t_list *cur = lst;
	int i = 0;
	if(is_empty_list(lst))
		return(NULL);
	if(pos == 0)
	{
		lst = lst->next;
		free(cur);
		return(lst);
	}
	while(i < pos)
	{
	i++;
	last = cur;
	cur = cur->next;
	}
	last->next = cur->next;
	free(cur);

	return(lst);	
}

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
/*
//-----------------------------------------------

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if(lst)
	{
		if(*lst)
			new->next = *lst;
		*lst = new;
	}
}
*/
//----------------------------------------------
/*
t_list	add_element(t_list *lst, int num)
{
*/
