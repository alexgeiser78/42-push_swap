/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions_suite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:32:02 by ageiser           #+#    #+#             */
/*   Updated: 2023/02/25 18:16:09 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

Bool	overflow_checker(char **str)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) >= INT_MAX || ft_atoi(str[i]) <= INT_MIN)
			return (false);
		i++;
	}
	i = 1;
	while (str[i])
	{
		n = ft_atoi(str[i]);
		if (ft_strncmp(str[i], ft_itoa(n), ft_strlen(str[i])) != 0)
			return (false);
		i++;
	}
	return (true);
}
//ligne 24 on verifie que le chiffre ne depasse pas le nbr le 
//plus grand 2147483648
//ligne 32 verifie que lors de la convertion atoi -> itoa le nbr n'est 
//pas modifie pour etre accepte quand meme

//----------------------

Bool	nbr_cmp(char *str1, char *str2)
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
//ligne 52 et 54 verification de presence du signe + pour les cas 12 == +12
//ligne 62 tant qu'on est pas au bout des arguments et que chaque
//caractere est similaire, on se decale d'un caractere
//ligne 67 si le dernier caractere de chaque argument est similaire -> true

//---------------------------------

Bool	is_duplicate(char **str)
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
//ligne 85 et 88, indices a 1 car on ne veut pas l'argument ./a.out
//ligne 91 tant qu'on est sur deux arguments differents (j != i) et
//que ces deux arguments sont les memes -> true
