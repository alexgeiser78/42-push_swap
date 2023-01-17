/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/01/17 13:55:20 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum
{
	false,
	true
}Bool; 

typedef struct s_list
{
	int data;
	struct s_list *next;
}t_list;

t_list *new_list(void);
Bool is_empty_list(t_list *lst);
int list_size(t_list *lst);
void print_list(t_list *lst);
t_list *add_at(t_list *lst, int data, int pos);
t_list *create_element(int data);
t_list *free_list(t_list *lst);
/*
t_list push_back_list(t_list lst, int x);
t_list push_front_list(t_list *lst, int x);
t_list pop_back_list(t_list lst);
t_list pop_front_list(t_list lst);
*/
#endif


