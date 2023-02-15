/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:23 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/15 17:48:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

Bool	input_true(char *str)
{
	int i = 0;
	while(str[i])
	{
		while(str[i] == ' ' || str[i] == '\t')
			i++;
		if(str[i] > '9' && (str[i] != '-' && str[i] != '+'))
		{
			write(2, "Error\n", 6);
			return(0);
		}	
		else
			i++;
	}
	return(true);
}

// no repeat
// not to big 214748
// just int
