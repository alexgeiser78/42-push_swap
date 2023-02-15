/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/15 17:50:12 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef enum
{
	false,
	true
}Bool;

typedef struct s_list
{
	int	data;
	struct s_list	*next;
}t_list;

t_list	*new_list(void);
Bool	is_empty_list(t_list **lst);
int	list_size(t_list *lst);
void	print_list(t_list *lst);
t_list	*add_at(t_list *lst, int data, int pos);
t_list	*create_element(int data);
t_list	*free_list(t_list *lst);
int	get_at(t_list *lst, int pos); //afficher une donnee d'un element
void	set_at(t_list *lst, int data, int pos);
t_list	*free_at(t_list **lst, int pos);
Bool	input_true(char *str);
int	ft_atoi(char *str);

void	ft_swap(t_list *lst);

void	pa(t_list **lista, t_list **listb);
void	pb(t_list **lista, t_list **listb);

void	ft_rot(t_list **lst);

void	ft_rev_rot(t_list **lst);

t_list	*get_last(t_list *lst);
t_list	*get_penultieme(t_list *lst);

void	run_swap_a(t_list **lista);
void	run_swap_b(t_list **listb);
void	run_swap_ab(t_list *lista, t_list *listb);
void	run_rot_a(t_list **lista);
void	run_rot_b(t_list **listb);
void	run_rot_ab(t_list **lista, t_list **listb);
void	run_rev_rot_a(t_list **lista);
void	run_rev_rot_b(t_list **listb);
void	run_rev_rot_ab(t_list **lista, t_list **listb);

/*
void ft_lstadd_front(t_list **lst, t_list *new);
t_list *push_front_list(t_list *lst, int data);
t_list push_back_list(t_list lst, int data);
t_list pop_back_list(t_list lst);
t_list pop_front_list(t_list lst);
*/
#endif
