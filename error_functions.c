/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:23 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/21 18:41:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

Bool is_sign(char c)
{
	if(c == '+' || c == '-')
		return(true);
	else
		return(false);
}
//verifie que seul les caracteres - et + soient pris en compte

Bool	is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return(true);
	else
		return(false);
}
//verifie que chaque caractere est un nombre

Bool	is_number(char *str)
{
	int i = 0;

	if(is_sign(str[i]) == true && str[i + 1] != '\0')
	{
		i++;
		printf("sign = %d\n", i);
	}
	while(str[i] && is_digit(str[i])) //
			{
			i++;	
			printf("not sign pos = %d\n", i);
			}
	
	if (str[i] != '\0' && is_digit(str[i]) == false)
		return(false);
	return(true);
}
//verifie que chaque argument est un nombre
//ligne 37 verifie que seul les signe - et + sont pris en compte et qu'apres
//eux il y ait un nombre ex: --1 = false
//ligne 39 verifie que apres le signe il n'y ait que des nombres ex: -1a = false

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
