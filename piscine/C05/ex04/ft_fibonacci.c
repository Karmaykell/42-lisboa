/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:46:34 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/14 20:18:27 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	result;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_fibonacci(6));
	return (0);
}
*/
