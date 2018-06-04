/*
** EPITECH PROJECT, 2018
** functions
** File description:
** hunter
*/
#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;

	while(str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

int     my_put_nbr(int nb)
{
        int i;

	i = 0;
	if(nb < 0)
	{
		my_putchar('-');
		nb = ((nb / 10) * -1);
	}
	if(nb >= 0)
	{
		if(nb >= 10)
		{
			i = (nb % 10);
			nb = (nb - i) / 10;
			my_put_nbr(nb);
			my_putchar(48 + i);
		}
		else
			my_putchar(48 + nb % 10);
	}
	return (0);
}

char *malloc_string(int nb, char *number)
{
	int digit = 1;

	if (nb < 0)
		digit++;
	while (nb >= 10) {
		nb = nb / 10;
		digit += 1;
	}
	number = malloc(sizeof(char) * digit + 1);
	return (number);
}

char *my_set_nbr(int nb)
{
	int nbr = nb;
	int numb = 1;
	char *number = malloc_string(nb, number);
	int i = 0;
	
	if (nb < 0) {
		number[i] = '-';
		i++;
		nbr = nb * -1;
	}
	while (numb <= nbr)
		numb *= 10;
	numb = numb / 10;
	while (numb) {
		number[i] = (nbr / numb) % 10 + '0';
		i++;
		numb = numb / 10;
	}
	number[i] = '\0';
	return (number);
}
