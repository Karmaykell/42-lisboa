/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 18:29:50 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/14 18:45:12 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	result = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	i = power;
	while (i != 0)
	{
		result = result * nb;
		i--;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(2, 3));
	return (0);
}
*/
