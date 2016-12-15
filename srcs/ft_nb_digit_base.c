#include "libft.h"

int		ft_nb_digit_base(long long nbr, int base)
{
	int		nb_digit;
	
	nb_digit = 1;
	if (nbr < 0)
	{
		nb_digit++;
		nbr = -nbr;
	}
	while (nbr >= base)
	{
		nb_digit++;
		nbr /= base;
	}
	return (nb_digit);
}
