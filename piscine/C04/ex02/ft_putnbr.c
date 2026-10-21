/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:16:27 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/09 18:05:49 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	display[12];
	long	n;
	int		i;

	n = nb;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n >= 10)
	{
		display[i] = n % 10;
		n = n / 10;
		i++;
	}
	display[i] = n;
	while (i >= 0)
	{
		write(1, &"0123456789"[(int)display[i]], 1);
		i--;
	}
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	return (0);
}
*/
