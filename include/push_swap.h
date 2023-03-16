/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/03/16 16:33:42 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<limits.h> 

typedef enum
{
	false,
	true
}Bool;

typedef struct s_list
{
	int	data;
	int	index;
	int	chunk;
	int	pos;
	int	cost_a;
	int	cost_b;
	int	target_pos;
	struct s_list	*next;
}t_list;

//creating list
t_list	*new_empty_list(void);
t_list	*create_element(int data);
t_list	*list_maker(int argc, char **argv);

Bool	is_empty_list(t_list **lst);
int	list_size(t_list *lst);
void	print_list(t_list *lst);
t_list	*add_at(t_list *lst, int data, int pos);
t_list	*free_list(t_list *lst);
int	get_at(t_list *lst, int pos); //afficher une donnee d'un element
void	set_at(t_list *lst, int data, int pos);
t_list	*free_at(t_list **lst, int pos);

//miscelaneous
int	ft_atoi(char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int	nbrlen(long int n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

//verificator
Bool	input_check(char **str);
Bool	is_number(char *str);
Bool	is_digit(char c);
Bool	is_sign(char c);
Bool	is_duplicate(char **str);
Bool	nbr_cmp(char *str1, char *str2);
Bool	just_one_zero(char *str);
Bool	overflow_checker(char **str);

// push-swap-rot-rev_rot functions
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

Bool	is_sorted(t_list *lst);
void	how_to_sort(t_list **lista, t_list **listb, int stack_size);
void	sort_3(t_list **lista);
int	is_bigger(t_list *lista);
int	search_middle(t_list **lst);
void	sort_all(t_list **lista, t_list **listb);
void	put_index(t_list *lista, int stack_size);
int	search_high(t_list **lst, int block);

void	sort_chunked(t_list **lista, t_list **listb);
int	search_highest_index_position(t_list **lst);
void	put_position(t_list **lst);

/*
void	get_target_position(t_list **lista, t_list **listb);
int	get_target(t_list **lista, int listb_index, int target_index, int target_position);
void	get_cost(t_list **lista, t_list **listb);
void	do_cheapest_move(t_list **lista, t_list **listb);
void	do_move(t_list **lista, t_list **listb, int cost_a, int cost_b);
void	do_rev_rotate_both(t_list **lista, t_list **listb, int *cost_a, int *cost_b);
void	do_rotate_both(t_list **lista, t_list **listb, int *cost_a, int *cost_b);
void	do_rotate_a(t_list **lista, int *cost);
void	do_rotate_b(t_list **listb, int *cost);
int	nb_abs(int nb);
void	shift_stack(t_list **lista);*/
void	exit_error(t_list **lista, t_list **listb);
/*
void ft_lstadd_front(t_list **lst, t_list *new);
t_list *push_front_list(t_list *lst, int data);
t_list push_back_list(t_list lst, int data);
t_list pop_back_list(t_list lst);
t_list pop_front_list(t_list lst);
*/
#endif
