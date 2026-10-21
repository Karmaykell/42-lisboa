/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:04:36 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/14 14:08:05 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 0)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(5));
	return (0);
}
*/
