/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:23 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/16 18:48:38 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

Bool	is_number(char *str)
{
	int i = 0;
/*	while(str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return(false);*/
	return(true);
}

Bool	input_check(char **str)
{
	int i = 0;
	while(str[i])
	{
		if (!is_number(str[i]))
		{
			printf("isnum = %u\n", is_number(str[i]));
			return(false);
		}
	}
	return(true);
}

// no repeat
// not to big 214748
// just int
