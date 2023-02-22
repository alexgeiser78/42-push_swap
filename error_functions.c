/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:23 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/22 18:36:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int nbr_cmp(char *str1, char *str2)
{
	int i = 0;
	int j = i;

	if (str1[i] == '+')
	{
		if (str2[j] != '+')
			i++;
	}
	else
	{
		if(str2[j] == '+')
			j++;
	}
	while(str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	return(str1[i] -str2[j]); 
}


Bool is_duplicate(char **str)
{
	int i = 1;
	int j;

	while(str[i])
	{
		j = 1;
		while(str[j])
		{
			if(j != i && nbr_cmp(str[i], str[j]) == 0)
				return(false);
		j++;
		}
		i++;
	}
return(true);
}

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
		i++;
	while(str[i] && is_digit(str[i]) == true) 
			i++;	
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
	if (is_duplicate(str) == true)
			return(false);
	return(true);
}
//int i = 1 parce que int i = 0    == a.out

// no repeat
// not to big 214748
