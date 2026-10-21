/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 18:49:47 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/14 19:37:52 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_recursive_power(2, 3));
	return (0);
}
*/
