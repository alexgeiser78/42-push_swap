/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions_suite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:32:02 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/08 16:49:43 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_Bool	overflow_checker(char **str)
{
	int		i;
	int		n;

	n = 0;
	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
			return (false);
		i++;
	}
	if (overflow_suite(i, str, n) == false)
		return (false);
	else
		return (true);
}
//ligne 24 on verifie que le chiffre ne depasse pas le nbr le 
//plus grand 2147483648

//----------------------

t_Bool	nbr_cmp(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (str1[i] == '+')
	{
		if (str2[j] != '+')
			i++;
	}
	else
	{
		if (str2[j] == '+')
			j++;
	}
	while (str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	if ((str1[i] - str2[j]) == 0)
		return (true);
	else
		return (false);
}
//similaire a strcmp mais booleen
//ligne 46 verification de presence du signe + pour les cas 12 == +12
//ligne 56 tant qu'on est pas au bout des arguments et que chaque
//caractere est similaire, on se decale d'un caractere
//ligne 61 si le dernier caractere de chaque argument est similaire -> true

//---------------------------------

t_Bool	is_duplicate(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 1;
		while (str[j])
		{
			if (j != i && nbr_cmp(str[i], str[j]) == true)
				return (true);
		j++;
		}
		i++;
	}
	return (false);
}
//ligne 79 et 82, indices a 1 car on ne veut pas l'argument ./a.out
//ligne 83 tant qu'on est sur deux arguments differents (j != i) et
//que ces deux arguments sont les memes -> true

t_Bool	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (false);
		lst = lst->next;
	}
	return (true);
}
//verify if the argument is already ordered
//--------------------------------------------------

t_Bool	is_empty_list(t_list **lst)
{
	if (lst == NULL)
		return (true);
	return (false);
}

//------------------------------------------
