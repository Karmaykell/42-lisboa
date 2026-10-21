/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:04:08 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/10 17:19:10 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	buffer[12];
	int		i;
	int		is_negative;
	int		digit;

	buffer[11] = '\n';
	i = 10;
	is_negative = (nbr < 0);
	if (nbr == 0)
		write(1, "0", 1);
	while (nbr != 0)
	{
		digit = nbr % 10;
		if (digit < 0)
			digit = -digit;
		buffer[i--] = '0' + digit;
		nbr /= 10;
	}
	if (is_negative)
		buffer[i--] = '-';
	write(1, &buffer[i + 1], 12 - (i + 1));
}


int	main(void)
{
	ft_putnbr(9);
	return (0);
}
