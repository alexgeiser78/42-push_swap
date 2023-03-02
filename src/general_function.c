#include"push_swap.h"

int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '-')
		sign = -1;
	if(str[i] == '+' || str[i] == '-')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
	res = res * 10 + str[i] - '0';
	i++;
	}
return(res * sign);
}

int	nbrlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
	i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	size_t			len;

	len = nbrlen(n);
	if (n < 0)
	un = (n * -1);
	else
	un = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		str[len] = '\0';
		len--;
		if (n < 0)
			str[0] = '-';
		else if (n == 0)
			str[0] = '0';
		while (un > 0)
		{
			str[len--] = (char)(un % 10 + '0');
				un = un / 10;
		}
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

		i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
