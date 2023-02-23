/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:23 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/23 18:32:51 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

Bool	just_one_zero(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (is_sign(str[i]) == true)
		i++;
	while (str[i] && (str[i] == '0'))
	{
		i++;
		j++;
	}
	if (j > 1)
		return (false);
	if (str[i] != '\0' && str[i - 1] == '0')
		return (false);
	if (j == 1 && (str[i - 2] == '-' || str[i - 2] == '+'))
		return (false);
	else
		return (true);
}
//elimine les 00 et les +000 et les -0001
//ligne 22 on decale l'indice du signe si il existe
//ligne 24 tant qu'il y a des 0 on les compte avec l'indice j
//ligne 29 si il y a plus d'un 0 de suite -> false
//ligne 31 si i n'est pas la fin de l'argument et que l'element 
//precedent est 0 -> false   cas 0 et 01 
//ligne 33 si il n'y a qu'un zero et qu'avant il y a le 
//signe + ou - ->false 

Bool nbr_cmp(char *str1, char *str2)
{
	int i = 0;
	int j = i;
	char res;
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
	if ((str1[i] - str2[j]) == 0)
		return(true);
	else
		return(false);

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
			if(j != i && nbr_cmp(str[i], str[j]) == true)
				return(true);
		j++;
		}
		i++;
	}
return(false);
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
	int n;
	while(str[i])
	{
		if (is_number(str[i]) == false)		
			return(false);
		i++;
	}
	i = 0;
	if (is_duplicate(str) == true)
			return(false);
	while(str[i])
	{
		if (just_one_zero(str[i]) == false)
			return(false);
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(ft_atoi(str[i]) >= INT_MAX || ft_atoi(str[i]) <= INT_MIN)
		{
			printf("overflow\n");
			return(false);
		}
		i++;
	}
	i = 0;

	while(str[i])
	{
		n = ft_atoi(str[i]);
		if (n == 0)
		       return(true);	
		if(ft_strncmp(str[i], ft_itoa(n), ft_strlen(str[i])) != 0)//
			return(false);
		i++;
	}
	return(true);
}
//int i = 1 parce que int i = 0    == a.out
//pourquoi ne fonctionne pas avec 0 ?
