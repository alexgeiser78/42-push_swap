/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:23 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/21 15:20:09 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int	is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return(1);
	else
		return(0);
}

Bool	is_number(char *str)
{
	int i = 0;

	if (str[i] != '\0' && !is_digit(str[i]))
		return(false);
	return(true);
}
//verifie que chaque argument est un nombre

Bool	input_check(char **str)
{
	int i = 1;

	while(str[i])
	{
		if (is_number(str[i]) == false)		
			return(false);
		i++;
	}
	return(true);
}
//int i = 1 parce que int i = 0    == a.out

// no repeat
// not to big 214748
// just int
