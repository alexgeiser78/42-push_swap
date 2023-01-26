#include<unistd.h>
#include"push_swap.h"

char *error_checker(char *str)
{
	//t_datos	datos;
	//
	//datos.i = 0;
	//datos.moco = m;
	//datos.n = 1;
	int i = 0;
	while(str[i])
	{
		while(str[i] == ' ' || str[i] == '\t')
			i++;
		if(str[i] < '0' && str[i] > '9' &&(str[i] != '-' && str[i] != '+'))
		{
			write(2, "Error\n", 6);
			return(0);
		}	
		else
			i++;
	}
	return(str);
}


