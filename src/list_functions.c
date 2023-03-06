/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/06 17:51:30 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//-----------------------------------------------------

t_list	*new_list(void)
{
	return (NULL);
}

//-----------------------------------------------------

Bool	is_empty_list(t_list **lst)
{
	if (lst == NULL)
		return (true);
	return (false);
}

//------------------------------------------------------

int	list_size(t_list *lst)

{
	int	size;

	size = 0;
	if (is_empty_list(&lst))
		return (size);
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

//-------------------------------------------------------

void	print_list(t_list *lst)
{
	if (is_empty_list(&lst))
	{
		printf ("empty list\n"); //printf
		return ;
	}
	while (lst)
	{
		printf ("[%d]\n", lst->data); //printf
		lst = lst->next;
	}
	printf ("[NULL]\n");//printf
}

//-------------------------------------------------------

t_list	*create_element(int data)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

//-------------------------------------------------------

t_list	*add_at(t_list *lst, int data, int pos)
{
	int	i;
	t_list	*last;
	t_list	*cur;
	t_list	*element;

	i = 0;
	last = lst;
	cur = lst;
	element = create_element(data);
	if (is_empty_list(&lst))
		return (element);
	if (pos == 0)
	{
		element->next = lst;
		return (element);
	}
	while (i < pos)
	{
	i++;
	last = cur;
	cur = cur->next;
	}
	last->next = element;
	element->next = cur;
	return (lst);
}

//-------------------------------------------------------

int	get_at(t_list *lst, int pos)
{
	int	i;

	i = 0;
	if (is_empty_list(&lst))
	{
		printf ("liste vide\n"); //printf
		return (-1);
	}
	while (i < pos)
	{
		i++;
		lst = lst->next;
	}
	return (lst->data);
}

//-----------------------------------------------

void	set_at(t_list *lst, int data, int pos)
{
	int	i;

	i = 0;
	if (is_empty_list(&lst))
	{
		printf ("liste vide\n"); //printf
		return ;
	}
	while (i < pos)
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
/*

t_list *push_front_list(t_list *lst, int data)
{
	t_list *element;

	element = create_element(data);

	element->data = data;

	if(is_empty_list(&lst))
		element->next = NULL;
	else
		element->next= lst;
	return (lst);
}	
*/
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

t_list	pop_front_list(t_list lst)
{
	if (is_empty_list(lst))
		return(lst);
	
	t_list *element;

	element = malloc(sizeof(*element));

	if (element == NULL)
	{
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}

	element = lst->element;

	free(lst);
	lst = NULL;
		
	return (element);
}
*/

//-----------------------------------------

t_list	*free_at(t_list **lst, int pos)
{
	int	i;
	t_list	*last;
	t_list	*cur;

	last = *lst;
	cur = *lst;
	i = 0;
	if (is_empty_list(lst))
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

//-----------------------------------------------

t_list	*free_list(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (lst)
	{
	tmp = lst->next;
		printf("del [%d]\n", lst->data); //printf
		free (lst);
	lst = tmp;
	}
	return (lst);
}
/*
//-----------------------------------------------

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
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

t_list	*get_last(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// find last element
//--------------------------------------------------

t_list	*get_penultieme(t_list *lst)
{
	while (lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
//find before-last element
//--------------------------------------------------

Bool	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if(lst->data > lst->next->data)
			return(false);
		lst = lst->next;
	}
	return(true);
}
//verify if the argument is already ordered
//--------------------------------------------------

int	is_bigger(t_list *lista)
{
	int big;

	big  = lista->data;
	while (lista)
	{
		if (lista->data > big)
			big = lista->data;
		lista = lista->next;
	}
	return(big);
}
//search for the biggest number to reduce the number of steps
//--------------------------------------------------

void	sort_3(t_list **lista)
{
	int	biggest;

	biggest = is_bigger(*lista);
	if ((*lista)->data == biggest)
		run_rot_a(lista);
	else if ((*lista)->next->data == biggest)
		run_rev_rot_a(lista);
	if ((*lista)->data > (*lista)->next->data)
		run_swap_a(lista);
}

//function to sort 3 numbers using the less steps possible
//--------------------------------------------------

int	search_middle(t_list **lst)
{
	int mini;
	int maxi;
	int med;
	t_list *tmp;

	tmp = (*lst);
	mini = (*lst)->data;
	while((*lst)->next)
	{
		if ((*lst)->next->data < mini)
		       mini = (*lst)->next->data;
		(*lst) = (*lst)->next;
 	}
	printf("mini = %d\n", mini);//
	*lst = tmp;
	maxi = (*lst)->data;

	while((*lst)->next)
	{
		if ((*lst)->next->data > maxi)
			maxi = (*lst)->next->data;
		(*lst)= (*lst)->next;
	}
	printf("maxi = %d\n", maxi);//
	med = (maxi + mini) / 2;
	printf("med = %d\n", med);//
	*lst = tmp;

	return(med);
}

void	sort_all(t_list **lista, t_list **listb)
{
	int medium;
	printf("search_middle\n"); //printf
	medium = search_middle(lista);

	
	while(*lista)
	{
	printf("first elem. = %d\n", (*lista)->data);//
	if ((*lista)->data > medium)
			pb(lista, listb);
	else
		run_rot_a(lista);
	
	(*lista) = (*lista)->next;
		
	print_list(*lista);
	printf("A\n");
	print_list(*listb);
	printf("B\n\n");
	}
}

void	how_to_sort(t_list **lista, t_list **listb)
{
	if(paramsum == 2 && is_sorted(*lista) == false)
		run_swap_a(lista);
	else if(paramsum == 3 && is_sorted(*lista) == false)
		sort_3(lista);
	else if(paramsum > 3 && is_sorted(*lista) == false)
		sort_all(lista, listb);
}
//function to sort 2, 3 and more numbers
//--------------------------------------------------

void	put_index(t_list *lista, int paramsum)
{
	t_list *ptr;
	t_list *highest;
	int data;
	while (--paramsum > 0)
	{
		ptr = lista;
		data = INT_MIN;
	       highest = NULL;
       	while (ptr)
	{
	if(ptr->data == INT_MIN && ptr->index == 0)
		ptr->index = 1;
	if(ptr->data > value && ptr->index == 0)
	{
		data = ptr->data;
		highest = ptr;
		ptr = lista;
	}
	else
		ptr = ptr->next;
	}
	if (highest != NULL)
	highest->index = paramsum;
	}
}	
