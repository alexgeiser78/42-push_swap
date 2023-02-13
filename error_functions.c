#include<unistd.h>
#include"push_swap.h"

char *error_checker(char *str)
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
	return(str);
}

// no repeat
// not to big 214748
// just int
