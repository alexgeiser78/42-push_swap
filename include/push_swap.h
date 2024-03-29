/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/08 15:33:52 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<limits.h> 

typedef enum booleen
{
	false,
	true
}t_Bool;

typedef struct s_list
{
	int				data;
	int				index;
	int				chunk;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				target_pos;
	struct s_list	*next;
}t_list;

//verificator / error_functions /error_functions_suite
t_Bool	input_check(char **str);
t_Bool	is_number(char *str);
t_Bool	is_digit(char c);
t_Bool	is_sign(char c);
t_Bool	is_duplicate(char **str);
t_Bool	nbr_cmp(char *str1, char *str2);
t_Bool	just_one_zero(char *str);
t_Bool	overflow_checker(char **str);
t_Bool	is_empty_list(t_list **lst);
t_Bool	is_sorted(t_list *lst);

//exit and free functions / exit_free
void	exit_error(t_list **lista, t_list **listb);
void	free_list(t_list **lst);
t_list	*free_at(t_list **lst, int pos);
t_Bool	overflow_suite(int i, char **str, int n);

//creating list / init
t_list	*new_empty_list(void);
t_list	*create_element(int data, int index);
t_list	*list_maker(int argc, char **argv);
t_list	*add_at(t_list *lst, int data, int pos, int index);

//miscelaneous tools / tools
int		list_size(t_list *lst);
void	put_index(t_list *lst, int stack_size);
void	put_position(t_list **lst);

//miscelaneous libft / general
int		ft_atoi(char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		nbrlen(long int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// swap functions
void	ft_swap(t_list *lst);
void	run_swap_a(t_list **lista);
void	run_swap_b(t_list **listb);
void	run_swap_ab(t_list *lista, t_list *listb);

// push functions
void	pa(t_list **lista, t_list **listb);
void	pb(t_list **lista, t_list **listb);

// rot functions
void	ft_rot(t_list **lst);
void	run_rot_a(t_list **lista);
void	run_rot_b(t_list **listb);
void	run_rot_ab(t_list **lista, t_list **listb);

// rev_rot functions
void	ft_rev_rot(t_list **lst);
void	run_rev_rot_a(t_list **lista);
void	run_rev_rot_b(t_list **listb);
void	run_rev_rot_ab(t_list **lista, t_list **listb);

// rev_rot_suite functions
t_list	*get_last(t_list *lst);
t_list	*get_penultieme(t_list *lst);

// sort function
void	how_to_sort(t_list **lista, t_list **listb, int stack_size);
void	sort_3(t_list **lista);
int		is_bigger(t_list *lista);
int		search_middle(t_list **lst);
void	sort_all(t_list **lista, t_list **listb);

//sort_suite functions
void	chunker(t_list **lista, t_list **listb, int i, int chunk_is);
void	sort_list_a(t_list **lista, int stack_size_a);
void	sort_list_b(t_list **lista, t_list **listb);
void	sort_chunked(t_list **lista, t_list **listb);
int		search_highest_index_position(t_list **lst);

//sort_suite2 functions unused
void	put_target_position(t_list **lista, t_list **listb);
int		get_target(t_list **lista, int listb_index, int target_index,
			int target_position);
void	put_cost(t_list **lista, t_list **listb);
void	do_cheapest_move(t_list **lista, t_list **listb);
void	do_move(t_list **lista, t_list **listb, int cost_a, int cost_b);

//sort_suite3 functions unused
void	do_rev_rotate_both(t_list **lista, t_list **listb,
			int *cost_a, int *cost_b);
void	do_rotate_both(t_list **lista, t_list **listb,
			int *cost_a, int *cost_b);
void	do_rotate_a(t_list **lista, int *cost);
void	do_rotate_b(t_list **listb, int *cost);
int		nb_abs(int nb);

//sort_suite4 functions
void	chunk_move(t_list **lista, t_list **listb, int chunk_is, int medium);

//containing printf / forbidden
void	print_list(t_list *lst);
void	print_index(t_list *lst);
int		get_at(t_list *lst, int pos);
void	set_at(t_list *lst, int data, int pos);
void	print_target_pos(t_list *lst);
void	print_pos(t_list *lst);
void	print_cost(t_list *lst);

//unused 
int		search_high(t_list **lst, int block);
void	shift_stack(t_list **lista);

#endif
