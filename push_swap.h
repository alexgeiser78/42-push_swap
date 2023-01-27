/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/27 17:48:00 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include<stdio.h>
typedef enum
{
	false,
	true
}Bool; 

typedef struct s_list
{
	int data;
	struct s_list *next;
//	struct s_list *last;
}t_list;
/*
typedef struct s_datos
{
	int	i;
	char	moco;
	int	n;
}	t_datos;
*/
t_list *new_list(void);
Bool is_empty_list(t_list *lst);
int list_size(t_list *lst);
void print_list(t_list *lst);
t_list *add_at(t_list *lst, int data, int pos);
t_list *create_element(int data);
t_list *free_list(t_list *lst);
int get_at(t_list *lst, int pos); //afficher une donnee d'un element
void set_at(t_list *lst, int data, int pos);
t_list *free_at(t_list *lst, int pos);
char *error_checker(char *str);
int ft_atoi(char *str);

t_list *sa(t_list *lst);
t_list *sb(t_list *lst);
void *ss(t_list *lista, t_list *listb);

void *pa(t_list *lista, t_list *listb);
/*
void ft_lstadd_front(t_list **lst, t_list *new);
t_list *push_front_list(t_list *lst, int data);
t_list push_back_list(t_list lst, int data);
t_list pop_back_list(t_list lst);
t_list pop_front_list(t_list lst);
*/
#endif


